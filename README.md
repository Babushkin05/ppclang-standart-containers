# Standart Containers Library for Procedural-Parametric style of Programming

## Ready-Made Containers

- Array

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
    for(uint i = 0; i < arr.len; ++i){
        struct Value.Int** elem2 = ArrayAt(&arr, i);
        struct Value.Int* b = create_spec(Value.Int);
        b  = *elem2;
        printf("%d ", b->@x); // 0 1 2 3 4 5 6 7 8 9 
    }

    return 0;
}

```