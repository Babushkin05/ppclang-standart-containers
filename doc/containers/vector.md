# Vector

## usage
```c
#include "ppvector.h"
```

## desc 
Специализация обобщенной структуры Container

Как и в Массиве, данные одного типа хранятся в непрерывной области памяти,
однако имеет динамический размер – позволяет добавлять элементы в конец. Константная
асимптотическая сложность добавления новых элемент достигается за счет того, что Вектор имеет
помимо размера параметр вместимости, и каждый раз, когда свободное пространство кончается,
Vector аллоцирует новую память с двойной вместимостью, и туда переносит все существующие
значения, можно доказать, что асимптотическая сложность остается константной.


## Специализированные функции

```c
// Initializes vector container with specified initial capacity
// container: Pointer to vector container structure
// size: Initial capacity for the vector
void InitContainerWithSize<Container.Vector * container>(size_t size);

// Initializes vector container with default capacity
// container: Pointer to vector container structure
void InitContainer<Container.Vector * container>();

// Removes all elements from vector container
// container: Pointer to vector container structure
// Note: Capacity remains unchanged
void ClearContainer<Container.Vector * container>();

// Checks if vector container is empty
// container: Pointer to vector container structure
// Returns: true (1) if empty, false (0) otherwise
_Bool EmptyContainer<Container.Vector * container>();

// Adds element to the end of vector (amortized O(1))
// container: Pointer to vector container structure
// val: Pointer to value to append
void PushBackContainer<Container.Vector * container>(Value *val);

// Removes last element from vector (O(1))
// container: Pointer to vector container structure
// Note: Undefined behavior if vector is empty
void PopBackContainer<Container.Vector * container>();

// Accesses first element of vector (O(1))
// container: Pointer to vector container structure
// Returns: Pointer to first element or NULL if empty
Value *FrontContainer<Container.Vector * container>();

// Accesses last element of vector (O(1))
// container: Pointer to vector container structure
// Returns: Pointer to last element or NULL if empty
Value *BackContainer<Container.Vector * container>();

// Accesses element at specific position (O(1))
// container: Pointer to vector container structure
// index: 0-based position to access
// Returns: Pointer to element or NULL if out of bounds
Value **ContainerAt<Container.Vector * container>(size_t index);

// Gets iterator to beginning of vector
// container: Pointer to vector container structure
// Returns: Iterator to first element or EndContainer() if empty
Value **BeginContainer<Container.Vector * container>();

// Gets end marker iterator
// container: Pointer to vector container structure
// Returns: Iterator to position after last element
Value **EndContainer<Container.Vector * container>();

// Advances iterator to next position
// iter: Pointer to iterator variable (will be modified)
// Note: Safe to call on end iterator
void NextIteratorContainer<Container.Vector * container>(Value ***iter);
```

## example

```c
#include <stdio.h>
#include "ppvector.h"
#include "ppcontainer.h"
#include "ppint.h"

Container + <Vector;>;
Value + <Int;>;

int main(){

    struct Container.Vector v;
    InitContainer<&v>();

    // Setting numbers
    for(uint i = 0; i < 15; ++i){
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&v>(a);
    }

    // Printing
    for(Value** iter = BeginContainer<&v>(); iter != EndContainer<&v>(); NextIteratorContainer<&v>(&iter)) {
        struct Value.Int* a = create_spec(Value.Int);
        a = *iter;
        printf("%d ", a->@x); // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
    }
    return 0;
}
```