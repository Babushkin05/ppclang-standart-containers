# String

## usage

```c
#include "ppstring.h"
```

## desc
специализация обобщенной структуры Value

## Специализированные методы

```c
// Computes hash value for string
unsigned int HashValue<Value.String * value>();

// Compares two string values for equality
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