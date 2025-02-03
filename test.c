#include <stdio.h>
#include "array/array.c"

typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){
    Array arr;
    InitArray(&arr, 10);
    Value* elem = ArrayAt(&arr, 0);
    if(elem==NULL)
        return 1;
    elem->@x = 2;
    printf("%d", ArrayData(&arr)[0]->@x);
    
}
