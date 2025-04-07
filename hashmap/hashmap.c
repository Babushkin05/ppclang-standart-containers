#include "hashmap.h"
#include <inttypes.h>
#include <stdint.h>

#define HASHMAP_INITIAL_CAP 16
#define HASHMAP_LOAD_FACTOR 0.75

unsigned int map_hasher(const void *ptr, unsigned int N) {
  uintptr_t ptr_value = (uintptr_t)ptr;

  // xor of left and right part of pointer
  uintptr_t hash = ptr_value ^ (ptr_value >> sizeof(void *) / 2);
  return (unsigned int)(hash % N);
}

void rehash_map(HashMap *map) {
  int old_cap = map->cap;
  HashMapNode **old_buckets = map->buckets;

  map->cap *= 2;
  map->buckets = (HashMapNode **)calloc(map->cap, sizeof(HashMapNode *));
  map->size = 0;

  for (int i = 0; i < old_cap; i++) {
    HashMapNode *current = old_buckets[i];
    while (current != NULL) {
      HashMapNode *next = current->next;
      unsigned int new_index = map_hasher(current->key, map->cap);

      current->next = map->buckets[new_index];
      map->buckets[new_index] = current;
      map->size++;

      current = next;
    }
  }

  free(old_buckets);
}

void InitHashMap(HashMap *map) {
  map->buckets =
      (HashMapNode **)calloc(HASHMAP_INITIAL_CAP, sizeof(HashMapNode *));
  map->size = 0;
  set->cap = HASHMAP_INITIAL_CAP;
}

_Bool HashMapEmpty(HashMap *map) { return map->size == 0; }

void HashMapClear(HashMap *map) {
  for (int i = 0; i < map->cap; i++) {
    HashMapNode *current = map->buckets[i];
    while (current != NULL) {
      HashMapNode *temp = current;
      current = current->next;
      free(temp->key);
      free(temp->val);
      free(temp);
    }
  }
  free(map->buckets);
}

void HashMapInsert(HashMap *map, Value *key, Value *val) {
  if ((double)map->size / map->cap >= HASHMAP_LOAD_FACTOR) {
    rehash_map(map);
  }

  if (HashMapContains(set, key)) {
    return;
  }

  unsigned int index = map_hasher(key, map->cap);
  HashMapNode *new_HashMapNode = (HashMapNode *)malloc(sizeof(HashMapNode));
  new_HashMapNode->key = key;
  new_HashMapNode->val = val;
  new_HashMapNode->next = map->buckets[index];
  map->buckets[index] = new_HashMapNode;
  map->size++;
}

_Bool HashMapContains(HashMap *map, Value *key) {
  unsigned int index = map_hasher(key, map->cap);
  HashMapNode *current = map->buckets[index];

  while (current != NULL) {
    if (current->key == key) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

Value *HashMapAt(HashMap *map, Value *key) {
  unsigned int index = map_hasher(key, map->cap);
  HashMapNode *current = map->buckets[index];

  while (current != NULL) {
    if (current->key == key) {
      return current->val;
    }
    current = current->next;
  }

  return NULL;
}

void HashMapErase(HashMap *map, Value *key) {
  unsigned int index = map_hasher(key, map->cap);
  HashMapNode *current = map->buckets[index];
  HashMapNode *prev = NULL;

  while (current != NULL) {
    if (current->key == key) {
      if (prev == NULL) {
        map->buckets[index] = current->next;
      } else {
        prev->next = current->next;
      }
      free(current->key);
      free(current->val);
      free(current);
      map->size--;
      return;
    }
    prev = current;
    current = current->next;
  }
}