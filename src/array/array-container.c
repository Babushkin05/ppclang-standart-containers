#include "container.h"
#include "array.h"

Container + < Array;>;

void InitContainerWithSize<Container.Array * container>(size_t size) {
  Array *array = &(container->@);
  InitArray(array, size);
}

void ClearContainer<Container.Array * container>() {
  Array *array = &(container->@);
  ClearArray(array);
}

_Bool EmptyContainer<Container.Array * container>() {
  Array *array = &(container->@);
  return ArrayEmpty(array);
}

// --------------------------------------------
// Iterators

Value **ContainerAt<Container.Array * container>(int index) {
  Array *array = &(container->@);
  return ArrayAt(array, index);
}

Value **BeginContainer<Container.Array * container>() {
  Array *array = &(container->@);
  return ArrayBegin(array);
}

Value **EndContainer<Container.Array * container>() {
  Array *array = &(container->@);
  return ArrayEnd(array);
}

void NextIteratorContainer<Container.Array * container>(Value ***iter) {
  Array *array = &(container->@);
  ArrayIteratorNext(iter);
}