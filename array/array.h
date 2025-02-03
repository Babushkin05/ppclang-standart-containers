#ifndef __array__
#define __array__
// array.h

#include <stdio.h>
#include "../value/value.h"

enum {maxLen = 100}; 

typedef struct Array {
  int len; 
  int current; 
  Value* data[maxLen];
} Array;


void InitArray(Array* array, const int size);

Value* ArrayAt(Array* array, int value);

Value* ArrayFront(Array* array);

Value* ArrayBack(Array* array);

Value* ArrayData(Array* array);

// �������� ���� ��������� ������ (������� �� ������)
void ClearArray(Array* array);

#endif // __array__