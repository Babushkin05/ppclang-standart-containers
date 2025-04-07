#ifndef __hashmap__
#define __hashmap__
// hashmap.h

typedef struct HashMapNode {
    Value *key;
    Value *val;
    struct HashMapNode *next;
} HashMapNode;

typedef struct HashMap {
    HashMapNode **buckets;
    unsigned int size;
    unsigned int cap;
} HashMap;

void InitHashMap(HashMap *map);

_Bool HashMapEmpty(HashMap *map);

void HashMapClear(HashMap *map);

void HashMapInsert(HashMap *map, Value* key, Value *val);

Value *HashMapAt(HashMap *map, Value *key);

void HashMapErase(HashMap *map, Value *key);

#endif // __hashmap__