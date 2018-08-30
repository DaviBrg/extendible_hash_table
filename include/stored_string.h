#ifndef STORED_STRING_H
#define STORED_STRING_H

#include <string>

#include "stored_data.h"
#include "hashable_type.h"

class StoredString : public StoredData {
public:
    StoredString(const std::string &value);
    StoredString(std::string &&value);
    ~StoredString() {}

    std::string value() const {return value_;}
    HashableType type() const {return HashableType::String();}
private:
    std::string value_;
};

#endif // STORED_STRING_H
