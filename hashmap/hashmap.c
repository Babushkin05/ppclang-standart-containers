#include "hashmap.h"
#include <inttypes.h>
#include <stdint.h>


#define HASHMAP_INITIAL_CAP 16
#define HASHMAP_LOAD_FACTOR 0.75

unsigned int hash_pointer1(const void *ptr, unsigned int N) {
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
      unsigned int new_index = hash_pointer(current->key, map->cap);

      current->next = map->buckets[new_index];
      map->buckets[new_index] = current;
      map->size++;

      current = next;
    }
  }

  free(old_buckets);
}

void InitHashMap(HashMap *map) {
  map->buckets = (HashMapNode **)calloc(HASHMAP_INITIAL_CAP, sizeof(HashMapNode *));
  map->size = 0; 
  set->cap = HASHMAP_INITIAL_CAP;
}

_Bool HashMapEmpty(HashMap *map){
  return map->size == 0;
}

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
