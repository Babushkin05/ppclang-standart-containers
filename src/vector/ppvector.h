#ifndef __vector__
#define __vector__
// vector.h

#include "ppvalue.h"

typedef struct Vector {
  size_t len;
  size_t cap;
  Value **data;
} Vector;

void InitVector(Vector *vector, size_t size);

_Bool VectorEmpty(Vector *vector);

Value **VectorAt(Vector *vector, size_t index);

Value *VectorFront(Vector *vector);

Value *VectorBack(Vector *vector);

Value **VectorData(Vector *vector);

void ClearVector(Vector *vector);

void VectorPushBack(Vector *vector, Value *value);

void VectorPopBack(Vector *vector);

Value **VectorBegin(Vector *vector);

void VectorIteratorNext(Value ***iter);

Value **VectorEnd(Vector *vector);

#endif // __vector__