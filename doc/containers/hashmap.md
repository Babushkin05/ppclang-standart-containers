# HashMap

## usage
```c
#include "pphashmap.h"
```

## desc 
Специализация обобщенной структуры Container

Представляет собой структуру данных HashMap -  это структура данных, Хранящая информацию в формате ключ-значение, также
основанная на хэш-таблице, которая хранит только уникальные ключи и их значения без сохранения
порядка их добавления. Его ключевое преимущество — высокая скорость основных операций:
вставка, удаление, нахождение значения по ключу , и проверка наличия элемента выполняются за
константное асимптотическое время. Это достигается за счёт хэширования: каждый элемент
преобразуется в уникальный ключ, определяющий его положение во внутреннем массиве.

В выбранной реализации было принято решение хешировать указатели на добавляемый
ключ, поскольку иначе бы пришлось для каждой специализации структуры Значение, программисту
пришлось бы определять специализацию функции хеширования. Само хеширование – функция
исключающего или между первой половиной байтов указателя и второй.

При возникновении коллизий, выбранная реализация HashSet использует метод цепочек
(хранение элементов с одинаковым хэшом в односвязном списке. Для поддержания эффективности
таблица автоматически расширяется при достижении определённого коэффициента заполнения
равного 0.75, что требует пересчёта хэшей всех элементов. Можно доказать, что за счет редкого
достижения коэффициента заполненности, асимптотическая сложность добавления элементов
константна.


## Специализированные функции

```c
// Initializes an empty hash map container
// Must be called before any other operations
void InitContainer<Container.HashMap * container>();

// Removes all key-value pairs from the map
// Leaves the container in valid empty state
void ClearContainer<Container.HashMap * container>();

// Checks if the hash map is empty
// Returns: 1 (true) if empty, 0 (false) otherwise
_Bool EmptyContainer<Container.HashMap * container>();

// Inserts a key-value pair into the map
// key: Pointer to the key (must be hashable)
// val: Pointer to the associated value
// Note: Replaces existing value if key exists
void InsertKeyValueContainer<Container.HashMap * container>(Value *key, Value *val);

// Checks if a key exists in the map
// key: Pointer to the key to search for
// Returns: 1 (true) if found, 0 (false) otherwise
_Bool ContainsContainer<Container.HashMap * container>(Value *key);

// Retrieves the value associated with a key
// key: Pointer to the lookup key
// Returns: Pointer to the associated value, or NULL if not found
Value *ContainerValueByKey<Container.HashMap * container>(Value *key);

// Removes a key-value pair from the map
// key: Pointer to the key to remove
// Note: Safe to call even if key doesn't exist
void EraseContainer<Container.HashMap * container>(Value *key);
```

## example

```c
#include "pphashmap.h"
#include "ppcontainer.h"
#include "ppint.h"
#include "ppstring.h"
#include "ppvalue.h"
#include <stdio.h>

Container + <HashMap;>;
Value + <Int;>;
Value + <String;>;

int main() {
    struct Container.HashMap map;
    InitContainer<&map>();
    // Insert elements
    for (int i = 0; i < 10; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        struct Value.String* val = create_spec(Value.String);
        sprintf(val->@value, "Item%d", i);
        InsertKeyValueContainer<&map>(key, val);
    }
    // Check contains and erase odd keys
    for (int i = 0; i < 10; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        if (i % 2 == 1) {
            EraseContainer<&map>(key);
        }
    }
    // Check deletions
    for (int i = 0; i < 10; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        printf("%d ", ContainsContainer<&map>(key)); // 1 0 1 0 1 0 1 0 1 0 
    }
    return 0;
}
```