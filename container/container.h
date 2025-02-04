#ifndef __container_
#define __container_
// container.h
// Объявление структур и  базовых функций, связанных с обработкой абстрактного
// однонаправленного кольцевого списка

#include <stdio.h>
#include "../value/value.h"

// Structure of Container generalization
typedef struct Container {}<> Container;

//==============================================================================
// Functions for Container usability

void InitContainer<Container* container>();

// Clear data from container
void ClearContainer<Container* container>();

//------------------------------------------------------------------------------
// Iterators

// Pointer to first elem
void First<Container* container>();

// Move Pointer to nex element
void Next<Container* container>();

// Checking for Exit to Last Element of Container
_Bool IsDone<Container* container>();

#endif // __container_