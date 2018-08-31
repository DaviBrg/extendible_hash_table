#include "hashable_double.h"

HashableDouble::HashableDouble(double value):
    value_(value) {}

bool HashableDouble::operator==(const StoredData &other) const {
    if (other.type() != HashableType::Double()) {
        return false;
    }
    auto &hd = static_cast<const HashableDouble&>(other);
    return (hd.value_ == value_);
}
