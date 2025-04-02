#ifndef __stack__
#define __stack__

#include "../value/value.c"

typedef struct Stack {
  int capasity;
  uint topInd;
  Value **data;
} Stack;

// Initialisation
void InitStack(Stack *stack);

// Get top of the stack
Value *StackTop(Stack *stack);

// Push element to stack
void StackPush(Stack *stack, Value *value);

// Pop element from pop of the stack
Value *StackPop(Stack *stack);

// Clear array;
void ClearStack(Stack *stack);

// Check is stack empty
_Bool StackEmpty(Stack *stack);

#endif // __stack