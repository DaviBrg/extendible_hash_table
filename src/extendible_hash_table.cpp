#include "extendible_hash_table.h"

#include <algorithm>

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

ExtendibleHashTable::Bucket &ExtendibleHashTable::Find(HashableData *key) const {
    std::shared_ptr<Page> page = directory_[key->HashValue() & depth_mask_];
    page->buckets;
    auto it = std::find_if(std::begin(page->buckets),
                           std::end(page->buckets),
                           [&](const Bucket &b){
        auto ptr = b.key.get();
        return key->HasEqualData( ptr);
    });

}



std::shared_ptr<StoredData> ExtendibleHashTable::Get(HashableData *key) const {
    return nullptr;
}

void ExtendibleHashTable::Set(HashableData *key, StoredData *value) {
    Find(key);
}


