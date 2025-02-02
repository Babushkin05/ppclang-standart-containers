#ifndef __stack__
#define __stack__

enum {capasity = 100;}

typedef struct Stack {
    int size;
    int capasity;
    Value* value[capasity];
} Stack;

void InitStack

#endif // __stack