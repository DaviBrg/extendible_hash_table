#ifndef HASHABLE_DATA_H
#define HASHABLE_DATA_H

#include <cstddef>

#include "stored_data.h"

class HashableData : public StoredData {
public:
    HashableData() {}
    virtual ~HashableData() {}
    virtual size_t HashValue() const = 0;
    virtual bool operator==(const StoredData &other) const = 0;
};

#endif // HASHABLE_DATA_H
