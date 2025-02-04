#ifndef __stack__
#define __stack__

enum {capasity = 100;}

typedef struct Stack {
    int capasity = 10;
    uint topInd = 0;
    Value** value;
} Stack;


// Initialisation
void InitStack(Stack* stack);

// Get top of the stack
Value* StackTop(Stack* stack);

// Pop element from pop of the stack
Value* StackPop(Stack* stack);

// Clear array;
void ClearStack(Array* array);

// Check is stack empty
_Bool StackEmpty(Array* array)

#endif // __stack