#include "extendible_hash_table.h"

#include <algorithm>

#include "ext_hash.h"

using namespace ext_hash;

constexpr size_t kInitialDirSize = 4;
constexpr size_t kInitialGlobalDepth = 2;
constexpr size_t kInitialDepthMask = 0x3;

ExtendibleHashTable::Page::Page(size_t size):
    local_depth(0),
    buckets(size) {}

ExtendibleHashTable::ExtendibleHashTable(size_t page_size/* = 4*/):
    directory_(kInitialDirSize, std::make_shared<Page>(page_size)),
    global_depth_(kInitialGlobalDepth),
    depth_mask_() {}

void ExtendibleHashTable::IncrementGlobalDepth() {
    global_depth_++;
    (depth_mask_ <<= 1) |= 1;
}

ExtendibleHashTable::Bucket *ExtendibleHashTable::Find(const HashableData &key) const {
    std::shared_ptr<Page> page = directory_[key.HashValue() & depth_mask_];
    auto it = std::find_if(std::begin(page->buckets), std::end(page->buckets),
                           [&](const Bucket &b){
        return (*(b.key) == key);
    });
    return (it != std::end(page->buckets)) ? &(*it) : nullptr;
}

void ExtendibleHashTable::Insert(const HashableData &key, const StoredData &value) {
    std::shared_ptr<Page> page = directory_[key.HashValue() & depth_mask_];
    auto it = std::find_if(std::begin(page->buckets), std::end(page->buckets),
                           [&](const Bucket &b){
        return (b.key == nullptr);
    });
    if (it != std::end(page->buckets)) {
        it->key = MakeUniqueDataCopy(key);
        it->value = MakeUniqueDataCopy(value);
    } else {
        std::abort();
    }
}



std::shared_ptr<StoredData> ExtendibleHashTable::Get(const HashableData &key) const {
    Bucket *bucket = Find(key);
    if (bucket) {
        return MakeSharedDataCopy(*(bucket->value));
    } else {
        return nullptr;
    }
}

void ExtendibleHashTable::Set(const HashableData &key, const StoredData &value) {
    Bucket *bucket = Find(key);
    if (bucket) {
        bucket->value = MakeUniqueDataCopy(value);
    } else {
        Insert(key, value);
    }
}


