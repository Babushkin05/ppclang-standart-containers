# String

## usage

```c
#include "ppstring.h"
```

## desc
специализация обобщенной структуры Value

## Специализированные методы

```c
unsigned int HashValue<Value.String * value>();

_Bool ValueEqual<Value.String *left, Value.String *right>();
```

## example

```c
#include "ppstring.h"
#include <stdio.h>

Value + <String;>;

void main() {
  struct Value.Int *a = create_spec(Value.String);
  struct Value.Int *b = create_spec(Value.String);
  a->@key = "HSE";
  b->@key = "HSE";

  printf("%d\n", ValueEqual<a, b>()); // 1
  return 0;
}
```