// stack.c

#include "ppstack.h"
#include <stdlib.h>

// Initialisation
void InitStack(Stack *stack) {
  stack->capasity = 10;
  stack->topInd = 0;
  stack->data = (Value **)malloc(stack->capasity * sizeof(void *));
}

// Get top of the stack
Value *StackTop(Stack *stack) {
  if (StackEmpty(stack))
    return NULL;
  return stack->data[stack->topInd - 1];
}

// Push element to stack
void StackPush(Stack *stack, Value *value) {
  stack->data[stack->topInd] = value;
  ++stack->topInd;
  if (stack->topInd == stack->capasity) {
    stack->capasity *= 2;
    Value **data = stack->data;
    stack->data =
        (Value **)realloc(stack->data, stack->capasity * sizeof(void *));
  }
}

// Pop element from pop of the stack
Value *StackPop(Stack *stack) {
  Value *top = StackTop(stack);
  if (stack->topInd != 0) {
    --stack->topInd;
  }
  return top;
}

// Clear array;
void ClearStack(Stack *stack) {
  for (uint i = 0; i < stack->topInd; ++i) {
    free(stack->data[i]);
  }
  stack->capasity = 10;
  stack->topInd = 0;
}

// Check is stack empty
_Bool StackEmpty(Stack *stack) { return stack->topInd == 0; }
