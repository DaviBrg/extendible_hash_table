#include "stored_string.h"

StoredString::StoredString(const std::string &value):
    value_(value) {}

StoredString::StoredString(std::string &&value):
    value_(std::move(value)) {}
