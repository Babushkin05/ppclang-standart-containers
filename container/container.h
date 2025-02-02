#ifndef __container_
#define __container_
// container.h
// Объявление структур и  базовых функций, связанных с обработкой абстрактного
// однонаправленного кольцевого списка

#include <stdio.h>
#include "../value/value.h"

//------------------------------------------------------------------------------
// Обобщенный контейнер
typedef struct Container {}<> Container;


//==============================================================================
// Функции для работы с контейнером

// Начальная инициализация контейнера
void InitContainer<Container* container>();

// Добавление значения в хвост контейнера
void AppendContainer<Container* container>(Value* value);

// Вывод элементов контейнера в указанный файл, который
// должен быть предварително открыт
void OutContainerValues<struct Container* container>(FILE* file);

// Удаление всех элементов из контейнера (очистка от данных)
void EmptyContainer<Container* container>();

// Вывод значения указанного элемента, из данного узла
// void OutCurrentContainerValue(FILE* file, Value* value);

//------------------------------------------------------------------------------
// Дополнительно добавлены функции итератора из Design Patterns

// Указатель на значение первого элемента контейнера
void First<Container* container>();

// Перевод указателя на значение следующего элемента контейнера
void Next<Container* container>();

// Проверка выхода за последний элемент контейнера
_Bool IsDone<Container* container>();

// Указатель на значение текущего элемента контейнера
Value* CurrentItem<Container* container>();

#endif // __container_