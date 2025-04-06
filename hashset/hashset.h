#ifndef __hashset__
#define __hashset__
// hashset.h

#include "../container/container.h"
#include "../value/value.h"

typedef struct Node {
  Value *key;
  struct Node *next;
} Node;

typedef struct HashSet {
  Node **buckets;
  unsigned int size;
  unsigned int cap;
} HashSet;

void InitHashSet(Hashset *set);

_Bool HashSetEmpty(HashSet *set);

void HashSetClear(HashSet *set);

void HashSetInsert(HashSet *set, Value *val);

_Bool HashSetContains(HashSet *set, Value *val);

void HashSetErase(HashSet *set, Value *val);

#endif // __hashset__