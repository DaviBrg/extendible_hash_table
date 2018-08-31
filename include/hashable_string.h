#ifndef HASHABLE_STRING_H
#define HASHABLE_STRING_H

#include <string>

#include "hashable_data.h"
#include "hashable_type.h"

class HashableString : public HashableData {
public:
    HashableString(std::string value);
    ~HashableString() {}

    HashableType type() const {return HashableType::String();}
    size_t HashValue() const {return hash_value_;}
    std::string value() const {return value_;}
    bool operator==(const StoredData &other) const;
private:
    static size_t CalculateHashValue(const std::string &str) ;
    std::string value_;
    size_t hash_value_;

};

#endif // HASHABLE_STRING_H
