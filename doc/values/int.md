# Int

## usage

```c
#include "ppint.h"
```

## desc
специализация обобщенной структуры Value

## Специализированные методы

```c
// Computes hash value for integer
unsigned int HashValue<Value.Int * value>();

// Compares two integer values for equality
_Bool ValueEqual<Value.Int *left, Value.Int *right>();
```

## example

```c
#include "ppint.h"
#include <stdio.h>

Value + <Int;>;

void main() {
  struct Value.Int *a = create_spec(Value.Int);
  struct Value.Int *b = create_spec(Value.Int);
  a->@x = 3;
  b->@x = 3;

  printf("%d\n", ValueEqual<a, b>()); // 1
  return 0;
}
```