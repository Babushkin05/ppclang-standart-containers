# Stack

## usage
```c
#include "ppstack.h"
```

## desc 
Специализация обобщенной структуры Container

Представляет собой структуру данных Stack - это структура данных, работающая по принципу LIFO, то есть элементы
добавляются в конец, и из конца удаляются. Структура также разработана так, что элементы
располагаются в непрерывной памяти, тем самым для поддержания динамического размера
используем тот же прием: специализация контейнера имеет помимо размера параметр вместимости,
и каждый раз, когда свободное пространство кончается, Vector аллоцирует новую память с двойной
вместимостью, и туда переносит все существующие значения, таким образом асимптотическая
сложность добавления нового элемента в конец контейнера остается константной.


## Специализированные функции

```c
// Initialize a stack container
// Takes a pointer to the container
void InitContainer<Container.Stack * container>();

// Clear the stack container
// Removes all elements, leaving the container empty
void ClearContainer<Container.Stack * container>();

// Check if the stack container is empty
// Returns true if the stack is empty
_Bool EmptyContainer<Container.Stack * container>();

// Add an element to the stack container
// Takes a pointer to the container and the value to be added
void PushContainer<Container.Stack * container>(Value *val);

// Extract an element from the stack container
// Returns the extracted value
Value *PopContainer<Container.Stack * container>();

// Get the top element of the stack container without extraction
// Returns the value of the top element
Value *TopContainer<Container.Stack * container>();
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