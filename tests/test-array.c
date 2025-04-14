#include <stdio.h>
#include "array.h"
#include "container.h"
#include <assert.h>

Container + <Array;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){

    struct Container.Array arr;
    InitContainerWithSize<&arr>(10);

    // Setting numbers
    for(size_t i = 0; i < arr@len; ++i){
        struct Value.Int** elem = ContainerAt<&arr>(i);
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        *elem = a;
    }

    // Printing 
    int v = 0;
    for(Value** i = BeginContainer<&arr>(); i != EndContainer<&arr>(); NextIteratorContainer<&arr>(&i)){
        struct Value.Int* a = create_spec(Value.Int);
        a  = *i;
        printf("%d \n", a->@x); // 0 1 2 3 4 5 6 7 8 9 
        assert(a->@x == v);
        ++v;
    }
    return 0;
}