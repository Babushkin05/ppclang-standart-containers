#ifndef __hashset__
#define __hashset__
// hashset.h

#include "ppcontainer.h"
#include "ppvalue.h"

typedef struct HashSetNode {
  Value *key;
  struct HashSetNode *next;
} HashSetNode;

typedef struct HashSet {
  HashSetNode **buckets;
  unsigned int size;
  unsigned int cap;
} HashSet;

void InitHashSet(HashSet *set);

_Bool HashSetEmpty(HashSet *set);

void HashSetClear(HashSet *set);

void HashSetInsert(HashSet *set, Value *val);

_Bool HashSetContains(HashSet *set, Value *val);

void HashSetErase(HashSet *set, Value *val);

#endif // __hashset__