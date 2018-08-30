#ifndef HASHABLE_STRING_H
#define HASHABLE_STRING_H

#include <string>

#include "hashable_data.h"
#include "hashable_type.h"

class HashableString : public HashableData {
public:
    HashableString(const std::string &value);
    HashableString(std::string &&value);
    ~HashableString() {}

    HashableType type() const {return HashableType::String();}
    size_t HashValue() const {return hash_value_;}
    bool HasEqualData(HashableData *other) const;
private:
    static size_t CalculateHashValue(const std::string &str) ;
    size_t hash_value_ = 0;
    std::string value_;
};

#endif // HASHABLE_STRING_H
