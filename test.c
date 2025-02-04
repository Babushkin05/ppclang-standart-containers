#include <stdio.h>
#include "array/array.c"

typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){
    Array arr;
    InitArray(&arr, 10);
    struct Value.Int** elem;
    elem = ArrayAt(&arr, 0);
    struct Value.Int* a;
    a = create_spec(Value.Int);
    a->@x = 2;
    *elem = a;
    struct Value.Int** elem2;
    elem2 = ArrayAt(&arr, 0);
    struct Value.Int* b;
    b = create_spec(Value.Int);
    b  = *elem2;
    int c = b->@x;
    printf("%d", c);
    return 0;
}
