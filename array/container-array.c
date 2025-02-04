// container-array.c
// Реализация базовых функций, связанных с обработкой массива

#include <stdio.h>
#include <stdlib.h>
#include "array.c"
#include "../container/container.c"

// Подключение массива в качестве специализации
Container + <Array;>;

//==============================================================================
// Обработчики специализации для одномерного массива,
// выступающего в роли контейнера

// Начальная инициализация контейнера
void InitContainer<Container.Array* container>() {
  Array* array = &(container->@);
  InitArray(array, array->len);
}

// Удаление всех элементов из контейнера (очистка от данных)
void ClearContainer<Container.Array* container>() {
  Array* array = &(container->@);
  ClearArray(array);
}

//==============================================================================
// Дополнительно добавлены функции итератора из Design Patterns

//------------------------------------------------------------------------------
// Указатель на значение первого элемента контейнера
Value** Begin<Container.Array* container>() {
  Array* array = &(container->@);
  if(ArrayEmpty(array)) {
    return NULL;
  } else {
    return &array->data[0];
  }
}

//------------------------------------------------------------------------------
// Перевод указателя на значение следующего элемента контейнера
void Next<Container.Array* container>(Value** value) {
  Array* array = &(container->@);
  value += sizeof(void*);
}

//------------------------------------------------------------------------------
// Проверка выхода за последний элемент контейнера
Value** End<Container.Array* container>() {
  Array* array = &(container->@);
  if(ArrayEmpty(array)) {
    return NULL;
  } else {
    return &array->data[array->len - 1];
  }
}
