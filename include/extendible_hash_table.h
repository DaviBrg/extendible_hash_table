#ifndef EXTENDIBLE_HASH_TABLE_H
#define EXTENDIBLE_HASH_TABLE_H

#include <vector>
#include <memory>

#include "stored_data.h"
#include "hashable_data.h"


class ExtendibleHashTable {
private:
    struct Bucket {
        std::unique_ptr<HashableData> key;
        std::unique_ptr<StoredData> value;
    };

    struct Page {
        explicit Page(size_t size);
        size_t local_depth;
        std::vector<Bucket> buckets;
    };
    using Directory = std::vector<std::shared_ptr<Page>>;

    void IncrementGlobalDepth();
    Bucket* Find(const HashableData &key) const;
    void Insert(const HashableData &key, const StoredData &value);

    Directory directory_;
    size_t global_depth_;
    size_t depth_mask_;

public:
    ExtendibleHashTable(size_t page_size = 4);

    std::shared_ptr<StoredData> Get(const HashableData &key) const ;
    void Set(const HashableData &key, const StoredData &value);


};

#endif // EXTENDIBLE_HASH_TABLE_H
