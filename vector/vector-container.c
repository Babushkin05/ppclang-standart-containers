#include "vector.h"
#include "../container/container.h"

Container + <Vector;>;

void InitContainerWithSize<Container.Vector* container>(size_t size) {
    Vector* vector = &(vector->@);
    InitVector(vector, size);
}

void ClearContainer<Container.Vector* container>() {
    Vector* vector = &(container->@);
    ClearArray(vector);
}

_Bool EmptyContainer<Container.Vector* container>() {
    Vector* vector = &(vector->@);
    return VectorEmpty(vector);
}

void PushBackContainer<Container.Vector* container>(Value* val) {
    Vector* vector = &(vector->@);
    VectorPushBack(vector, val);
}

void PopBackContainer<Container.Vector* container>() {
    Vector* vector = &(vector->@);
    VectorPopBack(vector);
}

// --------------------------------------------
// Iterators

Value** ContainerAt<Container.Vector* vector>(size_t index) {
    Vector* vector = &(vector->@);
    return VectorAt(vector, index);
}

Value** BeginContainer<Container.Vector* container>() {
    Vector* vector = &(vector->@);
    return VectorBegin(vector);
}

Value** EndContainer<Container.Vector* container>() {
    Vector* vector = &(vector->@);
    return VectorEnd(vector);
}

void NextIteratorContainer<Container.Vector* container>(Value*** iter) {
    Vector* vector = &(vector->@);
    VectorIteratorNext(iter);
}