#include "container.h"

// Container Initialisation
// Initializes the container with default settings
void InitContainer(Container *container) {
    perror("InitContainer not supported for this container");
}

// Container Initialisation with size parameter
// Initializes the container with specified initial capacity
void InitContainerWithSize(Container *container, size_t size) {
    perror("InitContainerWithSize not supported for this container");
}

// Deleting all elements of container
// Removes all elements from the container, making it empty
void ClearContainer(Container *container) {
    perror("ClearContainer not supported for this container");
}

// Checking if container is empty
// Returns true (1) if container has no elements, false (0) otherwise
_Bool EmptyContainer(Container *container) {
    perror("EmptyContainer not supported for this container");
    return false;
}

// Push element to container (implementation specific)
// Adds element to container according to container's specific rules
void PushContainer(Container *container, Value *val) {
    perror("PushContainer not supported for this container");
}

// Push element to back of container
// Adds element to the end of the container
void PushBackContainer(Container *container, Value *val) {
    perror("PushBackContainer not supported for this container");
}

// Push element to front of container
// Adds element to the beginning of the container
void PushFrontContainer(Container *container, Value *val) {
    perror("PushFrontContainer not supported for this container");
}

// Pop element from container (implementation specific)
// Removes and returns element according to container's specific rules
Value *PopContainer(Container *container) {
    perror("PopContainer not supported for this container");
    return NULL;
}

// Pop element from back of container
// Removes element from the end of the container
void PopBackContainer(Container *container) {
    perror("PopBackContainer not supported for this container");
}

// Pop element from front of container
// Removes element from the beginning of the container
void PopFrontContainer(Container *container) {
    perror("PopFrontContainer not supported for this container");
}

// Get top element (for stack-like containers)
// Returns the top element without removing it
Value *TopContainer(Container *container) {
    perror("TopContainer not supported for this container");
    return NULL;
}

// Get front element
// Returns the first element in the container
Value *FrontContainer(Container *container) {
    perror("FrontContainer not supported for this container");
    return NULL;
}

// Get back element
// Returns the last element in the container
Value *BackContainer(Container *container) {
    perror("BackContainer not supported for this container");
    return NULL;
}

// Insert element at appropriate position
// Adds element to container while maintaining order (for sorted containers)
void InsertContainer(Container *container, Value *val) {
    perror("InsertContainer not supported for this container");
}

// Check if container contains element
// Returns true if element is found in container, false otherwise
_Bool ContainsContainer(Container *container, Value *val) {
    perror("ContainsContainer not supported for this container");
    return false;
}

// Get value by key/index
// Returns element at specified position (index-based access)
Value *ContainerValueByKey(Container *container, int index) {
    perror("ContainerValueByKey not supported for this container");
    return NULL;
}

// Erase element from container
// Removes specific element from container if found
void EraseContainer(Container *container, Value *val) {
    perror("EraseContainer not supported for this container");
}

// --------------------------------------------
// Iterators

// Iterator for index (only for RandomAccessContainers)
// Returns pointer to element at specified index
Value **ContainerAt(Container *container, int index) {
    perror("ContainerAt not supported for this container");
    return NULL;
}

// Iterator to first element
// Returns pointer to the first element in container
Value **BeginContainer(Container *container) {
    perror("BeginContainer not supported for this container");
    return NULL;
}

// Iterator to last element
// Returns pointer to the position after last element
Value **EndContainer(Container *container) {
    perror("EndContainer not supported for this container");
    return NULL;
}

// Move iterator to next element in container
// Advances the iterator to point to next element
void NextIteratorContainer(Container *container, Value ***iter) {
    perror("NextIteratorContainer not supported for this container");
}