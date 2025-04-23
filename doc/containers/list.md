# List

## usage
```c
#include "ppstack.h"
```

## desc 
Специализация обобщенной структуры Container

Представляет собой структуру данных Cвязный список. Это структура данных динамического размера, состоящая из узлов,
каждый из которых хранит значение и ссылку на следующий и предыдущий узел. В отличие от
массива и вектора, элементы не требуют непрерывного размещения в памяти, что позволяет
эффективно вставлять и удалять элементы за константную асимптотическую сложность, однако из-
за этого не поддерживает обращение по индексу.


## Специализированные функции

```c
// Initializes a list container
// Must be called before using any other list operations
void InitContainer<Container.List * container>();

// Clears all elements from the list container
// Leaves the container in an empty state
void ClearContainer<Container.List * container>();

// Checks if the list container is empty
// Returns true (1) if empty, false (0) otherwise
_Bool EmptyContainer<Container.List * container>();

// Adds an element to the end of the list container
// val: Pointer to the value to be added
void PushBackContainer<Container.List * container>(Value *val);

// Removes the last element from the list container
// Container must not be empty when called
void PopBackContainer<Container.List * container>();

// Adds an element to the front of the list container
// val: Pointer to the value to be added
void PushFrontContainer<Container.List * container>(Value *val);

// Removes the first element from the list container
// Container must not be empty when called
void PopFrontContainer<Container.List * container>();

// Returns the first element of the list container
// Returns pointer to the value, NULL if container is empty
Value *FrontContainer<Container.List * container>();

// Returns the last element of the list container
// Returns pointer to the value, NULL if container is empty
Value *BackContainer<Container.List * container>();
```

## example

```c
#include <stdio.h>
#include "ppstack.h"
#include "ppcontainer.h"
#include "ppint.h"

Container + <Stack;>;
Value + <Int;>;

int main(){
    struct Container.Stack s;
    InitContainer<&s>();

    // Setting numbers
    for(uint i = 0; i < 15; ++i){
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        PushContainer<&s>(a);
    }

    // Printing 
    while(!EmptyContainer<&s>()){
        struct Value.Int* a = create_spec(Value.Int);
        a  = PopContainer<&s>();
        printf("%d \n", a->@x); // 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
    }
    return 0;
}
```