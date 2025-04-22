#ifndef __value__
#define __value__
// value.h

#include <stdio.h>

// Generalised Value structure
typedef struct Value {}<> Value;

unsigned int HashValue<Value * value>();

_Bool ValueEqual<Value *left, Value *right>();

#endif // __value__
