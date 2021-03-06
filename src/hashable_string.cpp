#include "hashable_string.h"

HashableString::HashableString(std::string value):
    value_(std::move(value)),
    hash_value_(CalculateHashValue(value_)) {}

bool HashableString::operator==(const StoredData &other) const {
    if (other.type() != HashableType::String()) {
        return false;
    }
    auto &hs = static_cast<const HashableString&>(other);
    return (hs.value_ == value_);
}

size_t HashableString::CalculateHashValue(const std::string &str) {
    unsigned char ret[sizeof(size_t)] = {0};
    size_t i = 0;
    for (unsigned char c : str) {
        ret [i++ % sizeof(size_t)] ^= c;
    }
    return *(reinterpret_cast<size_t*>(ret));
}
