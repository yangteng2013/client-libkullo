/* Copyright 2013–2015 Kullo GmbH. All rights reserved. */
#include <kulloclient/crypto/hkdf.h>
#include <kulloclient/crypto/symmetrickey.h>
#include <kulloclient/util/assert.h>
#include <kulloclient/util/binary.h>
#include <kulloclient/util/hex.h>

#include "tests/kullotest.h"

using namespace Kullo;
using namespace testing;

namespace {
    struct TestData
    {
        const Crypto::SymmetricKey randomKey256 = Crypto::SymmetricKey("ff33ec2466da9adaaa15f5b529e3a328a36cff8f28d28e30c249bb7fd5597718");
        const Crypto::SymmetricKey randomKey120 = Crypto::SymmetricKey("343539122b7a83e85b707f8f44ee67");
        const std::string info = "foo";
    };
}

class Hkdf : public KulloTest
{
protected:
    Crypto::HKDF hkdf;
};

K_TEST_F(Hkdf, expandHasCorrectOutputLength)
{
    TestData data;

    size_t bitLength = Crypto::HKDF::HASH_BITSIZE;
    auto output = hkdf.expand(data.randomKey256, data.info, bitLength);

    EXPECT_THAT(output.bitSize(), Eq(bitLength));
}

K_TEST_F(Hkdf, expandFailsOnInputTooSmall)
{
    TestData data;

    size_t bitLength = Crypto::HKDF::HASH_BITSIZE;

    ASSERT_THROW(hkdf.expand(data.randomKey120, data.info, bitLength),
                 Util::AssertionFailed);
}

K_TEST_F(Hkdf, expandFailsOnDesiredOutputLengthNotWholeByte)
{
    TestData data;

    size_t bitLength = Crypto::HKDF::HASH_BITSIZE + 1;

    ASSERT_THROW(hkdf.expand(data.randomKey256, data.info, bitLength),
                 Util::AssertionFailed);
}

K_TEST_F(Hkdf, expandFailsOnDesiredOutputTooLong)
{
    TestData data;

    size_t bitLength = 255 * Crypto::HKDF::HASH_BITSIZE + 1;

    ASSERT_THROW(hkdf.expand(data.randomKey256, data.info, bitLength),
                 Util::AssertionFailed);
}

/*
 * HKDF tests generated by using a python implementation of hkdf,
 * which has been tested against the original RFC 5869 test vectors.
 *
 * See https://github.com/webmaster128/python-hkdf for the implementation
 * and in branch "generate-tests-sha512" the file "generate-tests-sha512.py"
 * for test data generation.
 *
 */
K_TEST_F(Hkdf, expandHasCorrectOutputRFC5869TestA)
{
//  "name"  : "Test A"
//  "hash"  : sha512
//  "info"  : "f0f1f2f3f4f5f6f7f8f9"
//  "L"     : 42
//  "PRK"   : "665799823737ded04a88e47e54a5890bb2c3d247c7a4254a8e61350723590a26c36238127d8661b88cf80ef802d57e2f7cebcf1e00e083848be19929c61b4237"
//  "OKM"   : "832390086cda71fb47625bb5ceb168e4c8e26a1a16ed34d9fc7fe92c1481579338da362cb8d9f925d7cb"

    auto prk = Crypto::SymmetricKey("665799823737ded04a88e47e54a5890bb2c3d247c7a4254a8e61350723590a26c36238127d8661b88cf80ef802d57e2f7cebcf1e00e083848be19929c61b4237");
    auto info = Util::to_string(Util::Hex::decode("f0f1f2f3f4f5f6f7f8f9"));
    size_t L = 42;
    auto okm = Crypto::SymmetricKey("832390086cda71fb47625bb5ceb168e4c8e26a1a16ed34d9fc7fe92c1481579338da362cb8d9f925d7cb");

    Crypto::SymmetricKey result = hkdf.expand(prk, info, L*8);
    EXPECT_THAT(result, Eq(okm));
}

K_TEST_F(Hkdf, expandHasCorrectOutputRFC5869TestB)
{
//  "name"  : "Test B"
//  "hash"  : sha512
//  "info"  : "b0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
//  "L"     : 82
//  "PRK"   : "35672542907d4e142c00e84499e74e1de08be86535f924e022804ad775dde27ec86cd1e5b7d178c74489bdbeb30712beb82d4f97416c5a94ea81ebdf3e629e4a"
//  "OKM"   : "ce6c97192805b346e6161e821ed165673b84f400a2b514b2fe23d84cd189ddf1b695b48cbd1c8388441137b3ce28f16aa64ba33ba466b24df6cfcb021ecff235f6a2056ce3af1de44d572097a8505d9e7a93"

    auto prk = Crypto::SymmetricKey("35672542907d4e142c00e84499e74e1de08be86535f924e022804ad775dde27ec86cd1e5b7d178c74489bdbeb30712beb82d4f97416c5a94ea81ebdf3e629e4a");
    auto info = Util::to_string(Util::Hex::decode("b0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"));
    size_t L = 82;
    auto okm = Crypto::SymmetricKey("ce6c97192805b346e6161e821ed165673b84f400a2b514b2fe23d84cd189ddf1b695b48cbd1c8388441137b3ce28f16aa64ba33ba466b24df6cfcb021ecff235f6a2056ce3af1de44d572097a8505d9e7a93");

    Crypto::SymmetricKey result = hkdf.expand(prk, info, L*8);
    EXPECT_THAT(result, Eq(okm));
}

K_TEST_F(Hkdf, expandHasCorrectOutputRFC5869TestC)
{
//  "name"  : "Test C"
//  "hash"  : sha512
//  "info"  : ""
//  "L"     : 42
//  "PRK"   : "fd200c4987ac491313bd4a2a13287121247239e11c9ef82802044b66ef357e5b194498d0682611382348572a7b1611de54764094286320578a863f36562b0df6"
//  "OKM"   : "f5fa02b18298a72a8c23898a8703472c6eb179dc204c03425c970e3b164bf90fff22d04836d0e2343bac"

    auto prk = Crypto::SymmetricKey("fd200c4987ac491313bd4a2a13287121247239e11c9ef82802044b66ef357e5b194498d0682611382348572a7b1611de54764094286320578a863f36562b0df6");
    std::string info = "";
    size_t L = 42;
    auto okm = Crypto::SymmetricKey("f5fa02b18298a72a8c23898a8703472c6eb179dc204c03425c970e3b164bf90fff22d04836d0e2343bac");

    Crypto::SymmetricKey result = hkdf.expand(prk, info, L*8);
    EXPECT_THAT(result, Eq(okm));
}

K_TEST_F(Hkdf, expandHasCorrectOutputRFC5869TestD)
{
//  "name"  : "Test D"
//  "hash"  : sha512
//  "info"  : "f0f1f2f3f4f5f6f7f8f9"
//  "L"     : 42
//  "PRK"   : "67409c9cac28b52ee9fad91c2fda999f7ca22e3434f0ae772863836568ad6a7f10cf113bfddd560129a594a8f52385c2d661d785d29ce93a11400c920683181d"
//  "OKM"   : "7413e8997e020610fbf6823f2ce14bff01875db1ca55f68cfcf3954dc8aff53559bd5e3028b080f7c068"

    auto prk = Crypto::SymmetricKey("67409c9cac28b52ee9fad91c2fda999f7ca22e3434f0ae772863836568ad6a7f10cf113bfddd560129a594a8f52385c2d661d785d29ce93a11400c920683181d");
    auto info = Util::to_string(Util::Hex::decode("f0f1f2f3f4f5f6f7f8f9"));
    size_t L = 42;
    auto okm = Crypto::SymmetricKey("7413e8997e020610fbf6823f2ce14bff01875db1ca55f68cfcf3954dc8aff53559bd5e3028b080f7c068");

    Crypto::SymmetricKey result = hkdf.expand(prk, info, L*8);
    EXPECT_THAT(result, Eq(okm));
}

K_TEST_F(Hkdf, expandHasCorrectOutputRFC5869TestE)
{
//  "name"  : "Test E"
//  "hash"  : sha512
//  "info"  : ""
//  "L"     : 42
//  "PRK"   : "5346b376bf3aa9f84f8f6ed5b1c4f489172e244dac303d12f68ecc766ea600aa88495e7fb605803122fa136924a840b1f0719d2d5f68e29b242299d758ed680c"
//  "OKM"   : "1407d46013d98bc6decefcfee55f0f90b0c7f63d68eb1a80eaf07e953cfc0a3a5240a155d6e4daa965bb"

    auto prk = Crypto::SymmetricKey("5346b376bf3aa9f84f8f6ed5b1c4f489172e244dac303d12f68ecc766ea600aa88495e7fb605803122fa136924a840b1f0719d2d5f68e29b242299d758ed680c");
    std::string info = "";
    size_t L = 42;
    auto okm = Crypto::SymmetricKey("1407d46013d98bc6decefcfee55f0f90b0c7f63d68eb1a80eaf07e953cfc0a3a5240a155d6e4daa965bb");

    Crypto::SymmetricKey result = hkdf.expand(prk, info, L*8);
    EXPECT_THAT(result, Eq(okm));
}

K_TEST_F(Hkdf, expandHasCorrectOutputRFC5869TestDevelopmentKey)
{
//  "name"  : "Test Development Key"
//  "hash"  : sha512
//  "info"  : "login^hi#kullo.net"
//  "L"     : 64
//  "PRK"   : "684674576f41796b6e4b4f6f72494258556a674f707470567743666d4f46554e"
//  "OKM"   : "481acd52464821ddadeff998e1be88922fe8ce8cd8795172115d6f8852997f4cefe721ee801ece84e0297c6045ee41ee5ac2748a76e34edb9ff99c4157d8528e"

    auto prk = Crypto::SymmetricKey("684674576f41796b6e4b4f6f72494258556a674f707470567743666d4f46554e");
    std::string info = "login^hi#kullo.net";
    size_t L = 64;
    auto okm = Crypto::SymmetricKey("481acd52464821ddadeff998e1be88922fe8ce8cd8795172115d6f8852997f4cefe721ee801ece84e0297c6045ee41ee5ac2748a76e34edb9ff99c4157d8528e");

    Crypto::SymmetricKey result = hkdf.expand(prk, info, L*8);
    EXPECT_THAT(result, Eq(okm));
}