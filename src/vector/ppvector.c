#include "ppvector.h"
#include <stdlib.h>

void InitVector(Vector *vector, size_t size) {
  vector->len = size;
  vector->cap = 2 * size + 1;

  vector->data = (Value **)malloc(size * sizeof(void *));
  if (vector->data == NULL)
    return;
  for (size_t i = 0; i < size; ++i) {
    vector->data[i] = NULL;
  }
}

_Bool VectorEmpty(Vector *vector) { return vector->len == 0; }

Value **VectorAt(Vector *vector, size_t index) {
  if (index >= vector->len)
    return NULL;
  return &vector->data[index];
}

void VectorPushBack(Vector *vector, Value *value) {
  if (vector->len + 1 >= vector->cap) {
    vector->cap *= 2;
    vector->data =
        (Value **)realloc(vector->data, vector->cap * sizeof(void *));
  }
  vector->data[vector->len] = value;
  vector->len++;
}

void VectorPopBack(Vector *vector) {
  if (VectorEmpty(vector))
    return;
  if (vector->data[vector->len - 1] != NULL)
    free(vector->data[vector->len - 1]);
  vector->len--;
}

Value *VectorFront(Vector *vector) {
  if (VectorEmpty(vector))
    return NULL;
  return vector->data[0];
}

Value *VectorBack(Vector *vector) {
  if (VectorEmpty(vector))
    return NULL;
  return vector->data[vector->len - 1];
}

Value **VectorData(Vector *vector) { return vector->data; }

void ClearVector(Vector *vector) {
  for (size_t i = 0; i < vector->len; ++i) {
    free(vector->data[i]);
  }
  vector->len = 0;
}

Value **VectorBegin(Vector *vector) {
  if (VectorEmpty(vector))
    return NULL;
  return &(vector->data[0]);
}

void VectorIteratorNext(Value ***iter) { ++(*iter); }

Value **VectorEnd(Vector *vector) {
  if (VectorEmpty(vector))
    return NULL;
  return &(vector->data[vector->len - 1]) + 1;
}