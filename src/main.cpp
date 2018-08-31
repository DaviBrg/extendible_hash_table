#include <iostream>
#include "extendible_hash_table.h"
#include "hashable_string.h"
#include "hashable_long.h"
#include "stored_string.h"
#include "stored_long.h"

using namespace std;

int main() {
    ExtendibleHashTable ht;
    for (int i=0; i < 100; i++) {
        ht.Set(HashableLong(i), StoredLong(i*2));
    }
    return 0;
}
