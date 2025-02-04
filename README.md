# Standart Containers Library for Procedural-Parametric style of Programming

## Ready-Made Containers

- Array

- Stack

## Usage

### Array

```c
#include <stdio.h>
#include "array/array.c"

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){
    
    // Array Initialisation
    Array arr;
    InitArray(&arr, 10);

    // Setting numbers
    for(uint i = 0; i < arr.len; ++i){
        struct Value.Int** elem = ArrayAt(&arr, i);
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        *elem = a;
    }

    // Printing array
    for(Value** i = ArrayBegin(&arr); i != ArrayEnd(&arr); ArrayIteratorNext(&i)){
        struct Value.Int* b = create_spec(Value.Int);
        b  = *i;
        printf("%d ", b->@x); // 0 1 2 3 4 5 6 7 8 9 
    }

    return 0;
}

```

### Stack

```c
#include <stdio.h>
#include "stack/stack.c"

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){
    
    // Stack Initialisation
    Stack s;
    InitStack(&s);

    // Filling stack
    for(uint i = 0; i < 15; ++i){
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i; 
        StackPush(&s, a);
    }

    // Printing stack data
    while(!StackEmpty(&s)){
        struct Value.Int* a = create_spec(Value.Int);
        a = StackPop(&s);
        printf("%d ", a->@x); // 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 
    }

    return 0;
}
```