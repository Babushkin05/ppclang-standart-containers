# HashSet

## usage
```c
#include "pphashset.h"
```

## desc 
Специализация обобщенной структуры Container

Представляет собой структуру данных HashSet -  это структура данных, похожая на множество, основанная на хэш-таблице,
которая хранит только уникальные элементы без сохранения порядка их добавления. Его ключевое
преимущество — высокая скорость основных операций: вставка, удаление, и проверка наличия
элемента выполняются за константное асимптотическое время. Это достигается за счёт
хэширования: каждый элемент преобразуется в уникальный ключ, определяющий его положение во
внутреннем массиве.

В выбранной реализации было принято решение хешировать указатели на добавляемый
элемент, поскольку иначе бы пришлось для каждой специализации структуры Значение,
программисту пришлось бы определять специализацию функции хеширования. Само хеширование
– функция исключающего или между первой половиной байтов указателя и второй.

При возникновении коллизий, выбранная реализация HashSet использует метод цепочек
(хранение элементов с одинаковым хэшом в односвязном списке. Для поддержания эффективности
таблица автоматически расширяется при достижении определённого коэффициента заполнения
равного 0.75, что требует пересчёта хэшей всех элементов. Можно доказать, что за счет редкого
достижения коэффициента заполненности, асимптотическая сложность добавления элементов
константна.


## Специализированные функции

```c
// Initializes an empty hash set container
// Must be called before any other operations
void InitContainer<Container.HashSet * container>();

// Removes all elements from the hash set
// Leaves the container in valid empty state
void ClearContainer<Container.HashSet * container>();

// Checks if the hash set is empty
// Returns: 1 (true) if empty, 0 (false) otherwise
_Bool EmptyContainer<Container.HashSet * container>();

// Inserts a value into the hash set
// val: Pointer to the value to insert (must be hashable)
// Note: Does nothing if value already exists
void InsertContainer<Container.HashSet * container>(Value *val);

// Checks if a value exists in the hash set
// val: Pointer to the value to search for
// Returns: 1 (true) if found, 0 (false) otherwise
_Bool ContainsContainer<Container.HashSet * container>(Value *val);

// Removes a value from the hash set
// val: Pointer to the value to remove
// Note: Safe to call even if value doesn't exist
void EraseContainer<Container.HashSet * container>(Value *val);
```

## example

```c
#include <stdio.h>
#include "pphashset.h"
#include "ppcontainer.h"
#include "ppstring.h"

Container + <HashSet;>;
Value + <String;>;

int main(){
    struct Container.HashSet set;
    InitContainer<&set>();

    struct Value.String *a = create_spec(Value.String);
    a->@str = "hello";
    InsertContainer<&set>(a);

    struct Value.String *b = create_spec(Value.String);
    b->@str = "world";
    printf("is 'hello' inside: %d\n is 'world' inside: %d", ContainsContainer<&set>(a), ContainsContainer<&set>(b));
    return 0;
}
```