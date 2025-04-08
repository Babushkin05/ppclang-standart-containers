#include "container.h"

// --------------------------------------------
// Basic container operations

// Container Initialisation
void InitContainer<Container * container>() {
    perror("InitContainer not supported for this container");
}

// Container Initialisation with size parameter
void InitContainerWithSize<Container * container>(size_t size) {
    perror("InitContainerWithSize not supported for this container");
}

// Deleting all elements of container
void ClearContainer<Container * container>() {
    perror("ClearContainer not supported for this container");
}

// Checking is container empty
_Bool EmptyContainer<Container * container>() {
    perror("EmptyContainer not supported for this container");
    return false;
}

// --------------------------------------------
// Element insertion operations

// Push element to container (general)
void PushContainer<Container * container>(Value *val) {
    perror("PushContainer not supported for this container");
}

// Push element to back of container
void PushBackContainer<Container * container>(Value *val) {
    perror("PushBackContainer not supported for this container");
}

// Push element to front of container
void PushFrontContainer<Container * container>(Value *val) {
    perror("PushFrontContainer not supported for this container");
}

// --------------------------------------------
// Element removal operations

// Pop element from container (general)
Value *PopContainer<Container * container>() {
    perror("PopContainer not supported for this container");
    return NULL;
}

// Remove element from back of container
void PopBackContainer<Container * container>() {
    perror("PopBackContainer not supported for this container");
}

// Remove element from front of container
void PopFrontContainer<Container * container>() {
    perror("PopFrontContainer not supported for this container");
}

// --------------------------------------------
// Element access operations

// Get top element of container
Value *TopContainer<Container * container>() {
    perror("TopContainer not supported for this container");
    return NULL;
}

// Get front element of container
Value *FrontContainer<Container * container>() {
    perror("FrontContainer not supported for this container");
    return NULL;
}

// Get back element of container
Value *BackContainer<Container * container>() {
    perror("BackContainer not supported for this container");
    return NULL;
}

// --------------------------------------------
// Special container operations

// Insert element into container (general)
void InsertContainer<Container * container>(Value *val) {
    perror("InsertContainer not supported for this container");
}

// Check if container contains specific value
_Bool ContainsContainer<Container * container>(Value *val) {
    perror("ContainsContainer not supported for this container");
    return false;
}

// Get container value by key (for associative containers)
Value *ContainerValueByKey<Container * container>(Value *key) {
    perror("ContainerValueByKey not supported for this container");
    return NULL;
}

// Erase specific value from container
void EraseContainer<Container * container>(Value *val) {
    perror("EraseContainer not supported for this container");
}

// --------------------------------------------
// Iterators operations

// Iterator for index (only for RandomAccesContainers)
Value **ContainerAt<Container * container>(int index) {
    perror("ContainerAt not supported for this container");
    return NULL;
}

// Iterator to first element
Value **BeginContainer<Container * container>() {
    perror("BeginContainer not supported for this container");
    return NULL;
}

// Iterator to last element
Value **EndContainer<Container * container>() {
    perror("EndContainer not supported for this container");
    return NULL;
}

// Move iterator to next element in container
void NextIteratorContainer<Container * container>(Value ***iter) {
    perror("NextIteratorContainer not supported for this container");
}