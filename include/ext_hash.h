#ifndef EXT_HASH_H
#define EXT_HASH_H

#include <memory>

#include "ext_hash_fwd.h"

namespace ext_hash {

std::unique_ptr<StoredData> MakeUniqueDataCopy(const StoredData &data);

std::shared_ptr<StoredData> MakeSharedDataCopy(const StoredData &data);

}

#endif // EXT_HASH_H
