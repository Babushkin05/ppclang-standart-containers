#include "ppcontainer.h"
#include "ppvector.h"

Container + < Vector;>;

void InitContainerWithSize<Container.Vector * container>(size_t size) {
  Vector *vector = &(container->@);
  InitVector(vector, size);
}

void ClearContainer<Container.Vector * container>() {
  Vector *vector = &(container->@);
  ClearVector(vector);
}

_Bool EmptyContainer<Container.Vector * container>() {
  Vector *vector = &(container->@);
  return VectorEmpty(vector);
}

void PushBackContainer<Container.Vector * container>(Value *val) {
  Vector *vector = &(container->@);
  VectorPushBack(vector, val);
}

void PopBackContainer<Container.Vector * container>() {
  Vector *vector = &(container->@);
  VectorPopBack(vector);
}

// --------------------------------------------
// Iterators

Value **ContainerAt<Container.Vector * container>(size_t index) {
  Vector *vector = &(container->@);
  return VectorAt(vector, index);
}

Value **BeginContainer<Container.Vector * container>() {
  Vector *vector = &(container->@);
  return VectorBegin(vector);
}

Value **EndContainer<Container.Vector * container>() {
  Vector *vector = &(container->@);
  return VectorEnd(vector);
}

void NextIteratorContainer<Container.Vector * container>(Value ***iter) {
  Vector *vector = &(container->@);
  VectorIteratorNext(iter);
}