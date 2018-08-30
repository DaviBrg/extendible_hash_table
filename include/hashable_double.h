#ifndef HASHABLE_DOUBLE_H
#define HASHABLE_DOUBLE_H

#include "hashable_data.h"
#include "hashable_type.h"

class HashableDouble : public HashableData {
public:
    explicit HashableDouble(double value);
    ~HashableDouble() {}
    size_t HashValue() const { return static_cast<size_t>(value_);}
    HashableType type() const { return HashableType::Double();}
    bool HasEqualData(HashableData *other);
private:
    double value_;
};

#endif // HASHABLE_DOUBLE_H
