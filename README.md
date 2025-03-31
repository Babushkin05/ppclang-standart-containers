# Standart Containers Library for Procedural-Parametric style of Programming

## Ready-Made Containers

- Array

- Stack

## Usage

### Array

```c
#include <stdio.h>
#include "array/array.c"

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

    // Printing array
    for(Value** i = BeginContainer<&arr>(); i != EndContainer<&arr>(); NextIteratorContainer<&arr>(&i)){
        struct Value.Int* b = create_spec(Value.Int);
        b  = *i;
        printf("%d \n", b->@x); // 0 1 2 3 4 5 6 7 8 9 
    }
    printf("test");
    return 0;
}

```

### Stack

```c
#include <stdio.h>
#include "stack/stack.c"

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

    // Printing array
    while(!EmptyContainer<&s>()){
        struct Value.Int* a = create_spec(Value.Int);
        a  = PopContainer<&s>();
        printf("%d \n", a->@x); // 0 1 2 3 4 5 6 7 8 9 
    }
    printf("test");
    return 0;
}
```