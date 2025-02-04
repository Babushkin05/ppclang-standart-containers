#ifndef __array__
#define __array__
// array.h

#include <stdio.h>
#include "../value/value.h"

typedef struct Array {
  int len; 
  Value** data;
} Array;


void InitArray(Array* array, uint size);

Value** ArrayAt(Array* array, int value);

Value* ArrayFront(Array* array);

Value* ArrayBack(Array* array);

Value** ArrayData(Array* array);

void ClearArray(Array* array);

#endif // __array__