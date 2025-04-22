#include "ppcontainer.h"
#include "ppstack.h"

Container + < Stack;>;

// Container Initialisation
void InitContainer<Container.Stack * container>() {
  Stack *stack = &(container->@);
  InitStack(stack);
}

// Deleting all elements of container
void ClearContainer<Container.Stack * container>() {
  Stack *stack = &(container->@);
  ClearStack(stack);
}

// Checking is container empty
_Bool EmptyContainer<Container.Stack * container>() {
  Stack *stack = &(container->@);
  return StackEmpty(stack);
}

void PushContainer<Container.Stack * container>(Value *val) {
  Stack *stack = &(container->@);
  StackPush(stack, val);
}

Value *PopContainer<Container.Stack * container>() {
  Stack *stack = &(container->@);
  return StackPop(stack);
}

Value *TopContainer<Container.Stack * container>() {
  Stack *stack = &(container->@);
  return StackTop(stack);
}