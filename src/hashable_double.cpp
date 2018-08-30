#include "hashable_double.h"

HashableDouble::HashableDouble(double value):
    value_(value) {}

bool HashableDouble::HasEqualData(HashableData *other) {
    if (other->type() != HashableType::Double()) {
        return false;
    }
    auto hd = static_cast<HashableDouble*>(other);
    return (hd->value_ == value_);
}
