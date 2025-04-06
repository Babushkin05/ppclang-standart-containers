#include "container.h"

// Container Initialisation
void InitContainer<Container * container>() {}

// Container Initialisation with size parameter
void InitContainerWithSize<Container * container>(size_t size) {}

// Deleting all elements of container
void ClearContainer<Container * container>() {}

// Checking is container empty
_Bool EmptyContainer<Container * container>() {}

void PushContainer<Container * container>(Value *val) {}

void PushBackContainer<Container * container>(Value *val) {}

void PushFrontContainer<Container * container>(Value *val) {}

Value *PopContainer<Container * container>() {}

void PopBackContainer<Container * container>() {}

void PopFrontContainer<Container * container>() {}

Value *TopContainer<Container * container>() {}

Value *FrontContainer<Container * container>() {}

Value *BackContainer<Container * container>() {}

void InsertContainer<Container * container>(Value *val) {}

_Bool ContainsContainer<Container * container>(Value *val) {}

void EraseContainer<Container * container>(Value *val) {}

// --------------------------------------------
// Iterators

// Iterator for index (only for RandomAccesContainers)
Value **ContainerAt<Container * container>(int index) {};

// Iterator to first element
Value **BeginContainer<Container * container>() {}

// Iterator to last element
Value **EndContainer<Container * container>() {}

// Move iterator to next element in container
void NextIteratorContainer<Container * container>(Value ***iter) {}