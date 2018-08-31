#ifndef EXT_HASH_H
#define EXT_HASH_H

#include <memory>

#include "ext_hash_fwd.h"

namespace ext_hash {

std::unique_ptr<StoredData> MakeUniqueStoredDataCopy(const StoredData &data);

std::shared_ptr<StoredData> MakeSharedStoredDataCopy(const StoredData &data);

std::unique_ptr<HashableData> MakeUniqueHashableDataCopy(const HashableData &data);

std::shared_ptr<HashableData> MakeSharedHashableDataCopy(const HashableData &data);

}

#endif // EXT_HASH_H
