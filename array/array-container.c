#include "array.h"
#include "../container/container.h"

Container + <Array;>;

void InitContainer<Container.Array* container>() { }

void InitContainerWithSize<Container.Array* container>(size_t size) {
    Array* array = &(container->@);
    InitArray(array, size);
}

void ClearContainer<Container.Array* container>() {
    Array* array = &(container->@);
    ClearArray(array);
}

_Bool EmptyContainer<Container.Array* container>() {
    Array* array = &(container->@);
    return ArrayEmpty(array);
}

// --------------------------------------------
// Iterators

Value** ArrayAt<Container.Array* array>(int index){
    if(index >= array->@len)
        return NULL;
    return &array->@data[index];
}

Value** BeginContainer<Container.Array* container>() {
    Array* array = &(container->@);
    return ArrayBegin(array);
}

Value** EndContainer<Container.Array* container>() {
    Array* array = &(container->@);
    return ArrayEnd(array);
}

void NextIteratorContainer<Container.Array* container>(Value*** iter) {
    Array* array = &(container->@);
    ArrayIteratorNext(iter);
}