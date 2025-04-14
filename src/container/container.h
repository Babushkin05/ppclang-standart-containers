#ifndef __container__
#define __container__


#include "value.h"

// Generalised container structure
typedef struct Container {
} < > Container;

// --------------------------------------------
// Basic container operations

// Container Initialisation
void InitContainer<Container * container>();

// Container Initialisation with size parameter
void InitContainerWithSize<Container * container>(size_t size);

// Deleting all elements of container
void ClearContainer<Container * container>();

// Checking is container empty
_Bool EmptyContainer<Container * container>();

// --------------------------------------------
// Element insertion operations

// Push element to container (general)
void PushContainer<Container * container>(Value *val);

// Push element to back of container
void PushBackContainer<Container * container>(Value *val);

// Push element to front of container
void PushFrontContainer<Container * container>(Value *val);

// --------------------------------------------
// Element removal operations

// Pop element from container (general)
Value *PopContainer<Container * container>();

// Remove element from back of container
void PopBackContainer<Container * container>();

// Remove element from front of container
void PopFrontContainer<Container * container>();

// --------------------------------------------
// Element access operations

// Get top element of container
Value *TopContainer<Container * container>();

// Get front element of container
Value *FrontContainer<Container * container>();

// Get back element of container
Value *BackContainer<Container * container>();

// --------------------------------------------
// Special container operations

// Insert element into container (general)
void InsertContainer<Container * container>(Value *val);

// Insert element into container (general)
void InsertKeyValueContainer<Container * container>(Value *key, Value *val);

// Check if container contains specific value
_Bool ContainsContainer<Container * container>(Value *val);

// Get container value by key (for associative containers)
Value *ContainerValueByKey<Container * container>(Value *key);

// Erase specific value from container
void EraseContainer<Container * container>(Value *val);

// --------------------------------------------
// Iterators operations

// Iterator for index (only for RandomAccesContainers)
Value **ContainerAt<Container * container>(int index);

// Iterator to first element
Value **BeginContainer<Container * container>();

// Iterator to last element
Value **EndContainer<Container * container>();

// Move iterator to next element in container
void NextIteratorContainer<Container * container>(Value ***iter);

#endif // __container__