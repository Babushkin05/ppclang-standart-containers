# Array

## usage
```c
#include "pparray.h"
```

## desc 
Специализация обобщенной структуры Container

Представляет собой структуру данных Массив - это упорядоченная структура данных фиксированного размера, состоящая из
элементов одного типа, хранящихся в непрерывной области памяти. Доступ к элементам
осуществляется по индексу, что обеспечивает константную временную сложность.


## Специализированные функции

```c
// Initializes array container with specified capacity
// container: Pointer to container structure
// size: Initial capacity of the array
void InitContainerWithSize<Container.Array * container>(size_t size);

// Removes all elements from array container
// container: Pointer to container structure
// Note: Does not deallocate the container itself
void ClearContainer<Container.Array * container>();

// Checks if array container is empty
// container: Pointer to container structure
// Returns: true (1) if empty, false (0) otherwise
_Bool EmptyContainer<Container.Array * container>();

// Accesses element at specific index
// container: Pointer to container structure
// index: Position to access (0-based)
// Returns: Pointer to element or NULL if out of bounds
Value **ContainerAt<Container.Array * container>(int index);

// Gets iterator to first element
// container: Pointer to container structure
// Returns: Iterator to beginning or EndContainer() if empty
Value **BeginContainer<Container.Array * container>();

// Gets iterator to end (one past last element)
// container: Pointer to container structure
// Returns: End marker iterator
Value **EndContainer<Container.Array * container>();

// Advances iterator to next position
// iter: Pointer to iterator (will be modified)
// Note: Does nothing if iterator already at end
void NextIteratorContainer<Container.Array * container>(Value ***iter);
```

## example

```c
#include <stdio.h>
#include "pparray.h"
#include "ppcontainer.h"
#include "ppint.h"

Container + <Array;>;
Value + <Int;>;

int main(){

    struct Container.Array arr;
    InitContainerWithSize<&arr>(10);

    // Setting numbers
    for(uint i = 0; i < arr@len; ++i){
        struct Value.Int** elem = ContainerAt<&arr>(i);
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        *elem = a;
    }

    // Printing 
    for(Value** i = BeginContainer<&arr>(); i != EndContainer<&arr>(); NextIteratorContainer<&arr>(&i)){
        struct Value.Int* a = create_spec(Value.Int);
        a  = *i;
        printf("%d \n", a->@x); // 0 1 2 3 4 5 6 7 8 9 
    }
    return 0;
}
```