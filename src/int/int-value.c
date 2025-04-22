#include "int.h"
#include "value.h"

Value + <Int;>;

unsigned int HashValue<Value.Int * value>() {
    Int *i = &(value->@);
    return HashInt(i);
}

_Bool ValueEqual<Value.Int *left, Value.Int *right>() {
    return left->@x == right->@x;
}