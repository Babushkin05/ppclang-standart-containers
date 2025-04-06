#include "hashset.h"

#define INITIAL_CAPACITY 16
#define LOAD_FACTOR 0.75

unsigned int hash_pointer(const void *ptr, unsigned int N) {
    uintptr_t ptr_value = (uintptr_t)ptr;

    // xor of left and right part of pointer
    uintptr_t hash = ptr_value ^ (ptr_value >>  sizeof(void*)/2 ); 
    return (unsigned int)(hash % N);
}

void rehash(HashSet *set) {
    int old_capacity = set->capacity;
    Node **old_buckets = set->buckets;
    
    set->capacity *= 2;
    set->buckets = (Node **)calloc(set->capacity, sizeof(Node *));
    set->size = 0; 
    
    for (int i = 0; i < old_capacity; i++) {
        Node *current = old_buckets[i];
        while (current != NULL) {
            Node *next = current->next;
            unsigned int new_index = hash_pointer(current->key, set->capacity);
            
            current->next = set->buckets[new_index];
            set->buckets[new_index] = current;
            set->size++;
            
            current = next;
        }
    }
    
    free(old_buckets);
}

void InitHashSet(HashSet *set) {
    set->buckets = (Node **)calloc(TABLE_SIZE, sizeof(Node *));
    set->size = 0;
    set->capacity = INITIAL_CAPACITY;
}

_Bool HashSetEmpty(HashSet *set) {
    return set->size == 0;
}

void HashSetClear(HashSet *set) {
    for (int i = 0; i < set->capacity; i++) {
        Node *current = set->buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(set->buckets);
}

void HashSetInsert(HashSet *set, Value *val) {
    if ((double)set->size / set->capacity >= LOAD_FACTOR) {
        rehash(set);
    }

    if(HashSetContains(set, val)){
        return;
    }

    unsigned int index = hash(val, set->capacity);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = val;
    new_node->next = set->buckets[index];
    set->buckets[index] = new_node;
    set->size++;
}

_Bool HashSetContains(HashSet *set, Value *val) {
    unsigned int index = hash_pointer(val, set->capacity);
    Node *current = set->buckets[index];

    while (current != NULL) {
        if (current->key == val) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void HashSetErase(HashSet *set, Value* val) {
    unsigned int index = hash_pointer(val, set->capacity);
    Node *current = set->buckets[index];
    Node *prev = NULL;

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
