#ifndef STORED_LONG_H
#define STORED_LONG_H

#include "stored_data.h"
#include "hashable_type.h"

class StoredLong : public StoredData {
public:
    explicit StoredLong(double value);
    ~StoredLong() {}
    long int value() const {return value_;}
    HashableType type() const {return HashableType::Long();}
private:
    long int value_;
};

#endif // STORED_LONG_H
