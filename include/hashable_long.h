#ifndef HASHABLE_LONG_H
#define HASHABLE_LONG_H

#include "hashable_data.h"
#include "hashable_type.h"

class HashableLong : public HashableData {
public:
    explicit HashableLong(long int value);
    ~HashableLong() {}
    size_t HashValue() const { return value_;}
    HashableType type() const { return HashableType::Long();}
    bool HasEqualData(HashableData *other) const;
private:
    long int value_;
};

#endif // HASHABLE_LONG_H
