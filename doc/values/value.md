# Value 

## usage

```c
#include "ppvalue.h"
```
## desc 
Обобщенная структура, которую все контейнеры используют как элементы

Можно самому добавлять специализации:

```c
#include "ppvalue.h"

typedef struct Triangle {
    // длины сторон
    int a, b, c;
} Triangle;

Value + <Triangle;>;
```

## Обобщенные методы

```c
unsigned int HashValue<Value * value>();

_Bool ValueEqual<Value *left, Value *right>();
```

Если вы хотите использовать структуры данных, основанные на хештаблицах, вам следует реализовать специализацию под ваше значение.

Все включенные в библиотеку стандартные специализации структуры Value уже имеют эти специализации.

## example

```c
#include "ppvalue.h"

typedef struct Triangle {
    // длины сторон
    int a, b, c;
} Triangle;

Value + <Triangle;>;

int main() {
    struct Value.Triangle *t = create_spec(Value.Triangle); 
    t->@a = 1; t->@b = 2; t->@c = 3; 
    return 0;
}