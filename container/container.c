// container.c
// Реализация базовых функций, связанных с обработкой
// однонаправленного кольцевого массива

#include <stdio.h>
#include <stdlib.h>
#include "container.h"

//==============================================================================
// Generalised functions

// Container initialisation
void InitContainer<Container* container>() {} // = 0;

// Deleting all items in container
void ClearContainer<Container* container>() {} // = 0;

//==============================================================================
// Iterators

// Pointer to first elem
void Begin<Container* container>() {} // = 0;

// Move Pointer to nex element
void Next<Container* container>() {} // = 0;

// Checking for Exit to Last Element of Container
_Bool End<Container* container>() {return 0;} // = 0;


