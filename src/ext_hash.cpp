#include "ext_hash.h"

#include "hashable_double.h"
#include "hashable_long.h"
#include "hashable_string.h"
#include "stored_data.h"
#include "stored_double.h"
#include "stored_long.h"
#include "stored_string.h"

std::unique_ptr<StoredData> ext_hash::MakeUniqueStoredDataCopy(const StoredData &data) {
    if (data.type() == HashableType::Double()) {
        auto& data_ref = static_cast<const StoredDouble&>(data);
        return std::make_unique<StoredDouble>(data_ref.value());
    }
    if (data.type() == HashableType::Long()) {
        auto& data_ref = static_cast<const StoredLong&>(data);
        return std::make_unique<StoredLong>(data_ref.value());
    }
    if (data.type() == HashableType::String()) {
        auto& data_ref = static_cast<const StoredString&>(data);
        return std::make_unique<StoredString>(data_ref.value());
    }
    return nullptr;
}


std::shared_ptr<StoredData> ext_hash::MakeSharedStoredDataCopy(const StoredData &data) {
    return std::shared_ptr<StoredData>(MakeUniqueStoredDataCopy(data));
}

std::unique_ptr<HashableData> ext_hash::MakeUniqueHashableDataCopy(const HashableData &data) {
    if (data.type() == HashableType::Double()) {
        auto& data_ref = static_cast<const HashableDouble&>(data);
        return std::make_unique<HashableDouble>(data_ref.value());
    }
    if (data.type() == HashableType::Long()) {
        auto& data_ref = static_cast<const HashableLong&>(data);
        return std::make_unique<HashableLong>(data_ref.value());
    }
    if (data.type() == HashableType::String()) {
        auto& data_ref = static_cast<const HashableString&>(data);
        return std::make_unique<HashableString>(data_ref.value());
    }
    return nullptr;
}

std::shared_ptr<HashableData> ext_hash::MakeSharedHashableDataCopy(const HashableData &data) {
    return std::shared_ptr<HashableData>(MakeUniqueHashableDataCopy(data));
}
