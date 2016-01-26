// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from masterkey.djinni

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Kullo { namespace Api {

class MasterKey {
public:
    virtual ~MasterKey() {}

    /** Returns null if pem is not well-formed */
    static std::shared_ptr<MasterKey> createFromPem(const std::string & pem);

    /** Returns null if dataBlocks is not well-formed */
    static std::shared_ptr<MasterKey> createFromDataBlocks(const std::vector<std::string> & dataBlocks);

    /**
     * Validates a single block.
     * A block string is valid iff it contains exactly 6 digits
     * and fulfills the Luhn mod10 requirements
     */
    static bool isValidBlock(const std::string & block);

    /** Returns PEM formatted key */
    virtual std::string pem() = 0;

    /** Returns the key as 16 blocks of 6 digits each */
    virtual std::vector<std::string> dataBlocks() = 0;

    virtual bool isEqualTo(const std::shared_ptr<MasterKey> & other) = 0;
};

} }  // namespace Kullo::Api
