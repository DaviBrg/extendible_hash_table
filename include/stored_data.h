#ifndef STORED_DATA_H
#define STORED_DATA_H

#include "ext_hash_fwd.h"

class StoredData{
public:
    StoredData() {}
    virtual ~StoredData() {}
    virtual HashableType type() const = 0;
};

#endif // STORED_DATA_H
