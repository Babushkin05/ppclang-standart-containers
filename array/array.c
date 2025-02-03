// array.c

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void InitArray(Array* array, const int size) {
  array->len = 0;
  array->current = -1;
  for(int i = 0; i < maxLen; ++i) {
    array->data[i] = NULL;
  }
}
_Bool ArrayEmpty(Array* array){
    return array->len == 0;
}

Value* ArrayAt(Array* array, int index){
    if(index >= array->len)
        return NULL;
    return array->data[index];
}

Value* ArrayFront(Array* array){
    if(ArrayEmpty(array))
        return NULL;
    return array->data[0];
}

Value* ArrayBack(Array* array){
    if(ArrayEmpty(array))
        return NULL;
    return array->data[array->len - 1];
}

Value* ArrayData(Array* array){
    return array->data;
}

void ClearArray(Array* array) {
  for(int i = 0; i < array->len; ++i) {
    free(array->data[i]);
  }
  array->len = 0;
}


