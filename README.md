# Standart Containers Library for Procedural-Parametric style of Programming

## Ready-Made Containers

- Array

- Stack

- Vector

- List

## Usage

### Array

```c
#include <stdio.h>
#include "array/array.h"
#include "container/container.h"

Container + <Array;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
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
    printf("test");
    return 0;
}

```

### Stack

```c
#include <stdio.h>
#include "stack/stack.h"
#include "container/container.h"

Container + <Stack;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
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

### Vector

```c
#include <stdio.h>
#include "vector/vector.h"
#include "container/container.h"

Container + <Vector;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){

    struct Container.Vector v;
    InitContainerWithSize<&v>(0);

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

### List 

```c
#include <stdio.h>
#include "list/list.h"
#include "container/container.h"

Container + <List;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){

    struct Container.List l;
    InitContainer<&l>();

    // Setting numbers
    for(uint i = 0; i < 15; ++i){
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&l>(a);
    }

    // Printing 
    while(l@size){
        struct Value.Int* a = FrontContainer<&l>();
        printf("%d ", a->@x); // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
        PopFrontContainer<&l>();
    }
    return 0;
}
```
