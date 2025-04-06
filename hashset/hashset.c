#include "hashset.h"
#include <stdint.h>
#include <inttypes.h>

#define INITIAL_CAP 16
#define LOAD_FACTOR 0.75

unsigned int hash_pointer(const void *ptr, unsigned int N) {
    uintptr_t ptr_value = (uintptr_t)ptr;

    // xor of left and right part of pointer
    uintptr_t hash = ptr_value ^ (ptr_value >>  sizeof(void*)/2 ); 
    return (unsigned int)(hash % N);
}

void rehash(HashSet *set) {
    int old_cap = set->cap;
    HashSetNode **old_buckets = set->buckets;
    
    set->cap *= 2;
    set->buckets = (HashSetNode **)calloc(set->cap, sizeof(HashSetNode *));
    set->size = 0; 
    
    for (int i = 0; i < old_cap; i++) {
        HashSetNode *current = old_buckets[i];
        while (current != NULL) {
            HashSetNode *next = current->next;
            unsigned int new_index = hash_pointer(current->key, set->cap);
            
            current->next = set->buckets[new_index];
            set->buckets[new_index] = current;
            set->size++;
            
            current = next;
        }
    }
    
    free(old_buckets);
}

void InitHashSet(HashSet *set) {
    set->buckets = (HashSetNode **)calloc(INITIAL_CAP, sizeof(HashSetNode *));
    set->size = 0;
    set->cap = INITIAL_CAP;
}

_Bool HashSetEmpty(HashSet *set) {
    return set->size == 0;
}

void HashSetClear(HashSet *set) {
    for (int i = 0; i < set->cap; i++) {
        HashSetNode *current = set->buckets[i];
        while (current != NULL) {
            HashSetNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(set->buckets);
}

void HashSetInsert(HashSet *set, Value *val) {
    if ((double)set->size / set->cap >= LOAD_FACTOR) {
        rehash(set);
    }

    if(HashSetContains(set, val)){
        return;
    }

    unsigned int index = hash_pointer(val, set->cap);
    HashSetNode *new_HashSetNode = (HashSetNode *)malloc(sizeof(HashSetNode));
    new_HashSetNode->key = val;
    new_HashSetNode->next = set->buckets[index];
    set->buckets[index] = new_HashSetNode;
    set->size++;
}

_Bool HashSetContains(HashSet *set, Value *val) {
    unsigned int index = hash_pointer(val, set->cap);
    HashSetNode *current = set->buckets[index];

    while (current != NULL) {
        if (current->key == val) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void HashSetErase(HashSet *set, Value* val) {
    unsigned int index = hash_pointer(val, set->cap);
    HashSetNode *current = set->buckets[index];
    HashSetNode *prev = NULL;

    while (current != NULL) {
        if (current->key == val) {
            if (prev == NULL) {
                set->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            set->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}
