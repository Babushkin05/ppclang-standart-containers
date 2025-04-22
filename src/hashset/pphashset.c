#include "pphashset.h"
#include <inttypes.h>
#include <stdint.h>

#define HASHSET_INITIAL_CAP 16
#define HASHSET_LOAD_FACTOR 0.75

void rehash_set(HashSet *set) {
  int old_cap = set->cap;
  HashSetNode **old_buckets = set->buckets;

  set->cap *= 2;
  set->buckets = (HashSetNode **)calloc(set->cap, sizeof(HashSetNode *));
  set->size = 0;

  for (int i = 0; i < old_cap; i++) {
    HashSetNode *current = old_buckets[i];
    while (current != NULL) {
      HashSetNode *next = current->next;
      unsigned int new_index = HashValue<current->key>() % set->cap;;

      current->next = set->buckets[new_index];
      set->buckets[new_index] = current;
      set->size++;

      current = next;
    }
  }

  free(old_buckets);
}

void InitHashSet(HashSet *set) {
  set->buckets = (HashSetNode **)calloc(HASHSET_INITIAL_CAP, sizeof(HashSetNode *));
  set->size = 0;
  set->cap = HASHSET_INITIAL_CAP;
}

_Bool HashSetEmpty(HashSet *set) { return set->size == 0; }

void HashSetClear(HashSet *set) {
  for (int i = 0; i < set->cap; i++) {
    HashSetNode *current = set->buckets[i];
    while (current != NULL) {
      HashSetNode *temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(set->buckets);
  InitHashSet(set);
}

void HashSetInsert(HashSet *set, Value *val) {
  if ((double)set->size / set->cap >= HASHSET_LOAD_FACTOR) {
    rehash_set(set);
  }

  if (HashSetContains(set, val)) {
    return;
  }

  unsigned int index = HashValue<val>() % set->cap;
  HashSetNode *new_HashSetNode = (HashSetNode *)malloc(sizeof(HashSetNode));
  new_HashSetNode->key = val;
  new_HashSetNode->next = set->buckets[index];
  set->buckets[index] = new_HashSetNode;
  set->size++;
}

_Bool HashSetContains(HashSet *set, Value *val) {
  unsigned int index =  HashValue<val>() % set->cap;
  HashSetNode *current = set->buckets[index];

  while (current != NULL) {
    if (ValueEqual<current->key, val>()) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

void HashSetErase(HashSet *set, Value *val) {
  unsigned int index =  HashValue<val>() % set->cap;
  HashSetNode *current = set->buckets[index];
  HashSetNode *prev = NULL;

  while (current != NULL) {
    if (ValueEqual<current->key, val>()) {
      if (prev == NULL) {
        set->buckets[index] = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      set->size--;
      return;
    }
    prev = current;
    current = current->next;
  }
}
