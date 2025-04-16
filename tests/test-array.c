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
        assert(a->@x == v);
        ++v;
    }
    return 0;
}