#include "ext_hash.h"

#include "stored_data.h"
#include "stored_double.h"
#include "stored_long.h"
#include "stored_string.h"

std::unique_ptr<StoredData> ext_hash::MakeUniqueDataCopy(const StoredData &data) {
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


std::shared_ptr<StoredData> ext_hash::MakeSharedDataCopy(const StoredData &data) {
    return std::shared_ptr<StoredData>(MakeUniqueDataCopy(data));
}


