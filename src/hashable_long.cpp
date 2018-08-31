#include "hashable_long.h"

HashableLong::HashableLong(long value):
    value_(value) {}

bool HashableLong::operator==(const StoredData &other) const {
    if (other.type() != HashableType::Long()) {
        return false;
    }
    auto &hl = static_cast<const HashableLong&>(other);
    return (hl.value_ == value_);
}
