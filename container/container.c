#include "container.h"

// Container Initialisation
void InitContainer<Container* container>() {}

// Container Initialisation with size parameter
void InitContainerWithSize<Container* container>(size_t size) {}

// Deleting all elements of container
void ClearContainer<Container* container>() {}

// Checking is container empty
_Bool EmptyContainer<Container* container>() {}

// --------------------------------------------
// Iterators

// Iterator for index (only for RandomAccesContainers)
Value** ArrayAt<Container* container>(int index) {};

// Iterator to first element
Value** BeginContainer<Container* container>() {}

// Iterator to last element
Value** EndContainer<Container* container>() {}

// Move iterator to next element in container
void NextIteratorContainer<Container* container>(Value*** iter) {}