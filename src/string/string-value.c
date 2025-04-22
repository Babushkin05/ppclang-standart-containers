#include "string.h"
#include "value.h"

Value + <String;>;

unsigned int HashValue<Value.String *value>() {
    String *str = &(value->@);
    return HashString(str);
}

_Bool ValueEqual<Value.String *left, Value.String *right>() {
    String *l = &(left->@);
    String *r = &(right->@);
    return StringEqual(l, r);
}