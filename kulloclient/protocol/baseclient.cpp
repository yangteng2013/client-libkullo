/* Copyright 2013–2015 Kullo GmbH. All rights reserved. */
#include "kulloclient/protocol/baseclient.h"

#include <sstream>
#include <jsoncpp/jsoncpp.h>

#include "kulloclient/registry.h"
#include "kulloclient/crypto/symmetrickeygenerator.h"
#include "kulloclient/protocol/exceptions.h"
#include "kulloclient/protocol/debug.h"
#include "kulloclient/protocol/requestlistener.h"
#include "kulloclient/protocol/responselistener.h"
#include "kulloclient/util/assert.h"
#include "kulloclient/util/base64.h"
#include "kulloclient/util/kulloaddress.h"
#include "kulloclient/util/librarylogger.h"
#include "kulloclient/util/masterkey.h"
#include "kulloclient/util/version.h"

namespace {
const auto KULLO_DEVELOPMENT_DOMAIN = std::string{"kullo.dev"};
const auto KULLO_DEVELOPMENT_PORT = 8001;
}

namespace Kullo {
namespace Protocol {

BaseClient::BaseClient()
{
    auto httpClientFactory = Registry::httpClientFactory();
    kulloAssert(httpClientFactory);
    client_ = httpClientFactory->createHttpClient();
}

BaseClient::~BaseClient()
{
}

void BaseClient::setKulloAddress(const Util::KulloAddress &address)
{
    address_.reset(new Util::KulloAddress(address));
}

void BaseClient::setMasterKey(const Util::MasterKey &masterKey)
{
    masterKey_.reset(new Util::MasterKey(masterKey));
}

void BaseClient::cancel()
{
    canceled_ = true;
}

std::string BaseClient::baseUrl(const Util::KulloAddress *address)
{
    if (!address) address = address_.get();
    kulloAssert(address);

    if (address->domain() == KULLO_DEVELOPMENT_DOMAIN)
    {
        auto host = address->server();
        auto port = std::to_string(KULLO_DEVELOPMENT_PORT);
        return "http://" + host + ":" + port;
    }
    else
    {
        auto host = address->server();
        return "https://" + host + "/v1";
    }
}

std::string BaseClient::baseUserUrl(const Util::KulloAddress *address)
{
    if (!address) address = address_.get();
    kulloAssert(address);

    return baseUrl(address) + "/" + address->toUrlencodedString();
}

std::vector<Http::HttpHeader> BaseClient::makeHeaders(
        BaseClient::Authenticated auth, const std::string &contentType)
{
    std::vector<Http::HttpHeader> headers;
    headers.emplace_back("User-Agent", Util::Version::userAgent());
    headers.emplace_back("Content-Type", contentType);

    if (auth == Authenticated::True)
    {
        kulloAssert(address_);
        kulloAssert(masterKey_);
        auto loginKey =
                Crypto::SymmetricKeyGenerator()
                .makeLoginKey(*address_, *masterKey_);
        auto loginStringBase64 =
                Util::Base64::encode(
                    address_->toString() + ":" + loginKey.toHex());
        headers.emplace_back("Authorization", "Basic " + loginStringBase64);
    }

    return headers;
}

Http::Response BaseClient::sendRequest(const Http::Request &request)
{
    return doSendRequest(request, nullptr);
}

Http::Response BaseClient::sendRequest(
        const Http::Request &request, const Json::Value &reqJson)
{
    return doSendRequest(request, &reqJson);
}

void BaseClient::throwOnError(const Http::Response &response)
{
    if (response.error)
    {
        switch (*response.error)
        {
        case Http::ResponseError::Canceled:     throw Canceled();     break;
        case Http::ResponseError::NetworkError: throw NetworkError(); break;
        case Http::ResponseError::Timeout:      throw Timeout();      break;
        default: kulloAssert(false);
        }
    }

    switch (response.statusCode)
    {
    case 200:
        // everything is okay
        break;
    case 400:
        throw BadRequest();
    case 401:
        throw Unauthorized();
    case 403:
        throw Forbidden();
    case 404:
        throw NotFound();
    case 409:
        throw Conflict();
    case 500:
        throw InternalServerError();
    case 502: // Bad Gateway
        throw InternalServerError();
    default:
        throw HttpError();
    }
}

Json::Value BaseClient::parseJsonBody()
{
    auto respBodyData = reinterpret_cast<char*>(responseBody_.data());
    Json::Value json;
    Json::Reader(Json::Features::strictMode()).parse(
                respBodyData,
                respBodyData + responseBody_.size(),
                json,
                false);
    responseBody_.clear();
    return json;
}

Http::Response BaseClient::doSendRequest(
        const Http::Request &request, const Json::Value *reqJson)
{
    canceled_ = false;

    std::shared_ptr<RequestListener> reqL;
    std::string reqBody;
    size_t reqBodyCharsRead = 0;

    if (reqJson)
    {
        Json::StreamWriterBuilder wBuilder;
        wBuilder["commentStyle"] = "None";
        wBuilder["indentation"] = "";
        std::unique_ptr<Json::StreamWriter> writer(wBuilder.newStreamWriter());
        std::ostringstream reqStream;
        writer->write(*reqJson, &reqStream);
        reqBody = reqStream.str();

        reqL = std::make_shared<RequestListener>();
        reqL->setRead([&](int64_t maxSizeSigned)
        {
            kulloAssert(maxSizeSigned >= 0);
            // We assume that maxSizeSigned <= max(size_t). This is a valid
            // assumption because otherwise the maximum would be larger than the
            // address space...
            auto maxSize = static_cast<size_t>(maxSizeSigned);

            kulloAssert(reqBody.begin() + reqBodyCharsRead <= reqBody.end());
            auto chunkSize = std::min(
                        reqBody.size() - reqBodyCharsRead,
                        maxSize);
            std::vector<uint8_t> result;
            result.reserve(chunkSize);
            std::copy(reqBody.begin() + reqBodyCharsRead,
                      reqBody.begin() + reqBodyCharsRead + chunkSize,
                      std::back_inserter(result));
            reqBodyCharsRead += chunkSize;
            return result;
        });
    }

    responseBody_.clear();
    auto respL = std::make_shared<ResponseListener>();
    respL->setDataReceived([this](const std::vector<uint8_t> &data)
    {
        std::copy(data.cbegin(), data.cend(),
                  std::back_inserter(responseBody_));
    });
    respL->setShouldCancel([this]() -> bool
    {
        return canceled_;
    });

    Log.i() << request;
    auto response = client_->sendRequest(request, 0, reqL, respL);
    throwOnError(response);
    return response;
}

}
}