#ifndef STORED_DOUBLE_H
#define STORED_DOUBLE_H

#include "stored_data.h"
#include "hashable_type.h"

class StoredDouble : public StoredData {
public:
    explicit StoredDouble(double value);
    ~StoredDouble() {}
    double value() const {return value_;}
    HashableType type() const {return HashableType::Double();}
private:
    double value_;
};

#endif // STORED_DOUBLE_H
