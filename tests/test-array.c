#include "array.h"
#include "container.h"
#include <assert.h>
#include <stdio.h>

Container + < Array;> ;

// Create specialisation for Value
typedef struct Int {
  int x;
} Int;
Value + < Int;> ;

void Test_At_And_Iterators() {
  printf("Running Test_At_And_Iterators...\n");
  struct Container.Array arr;
  InitContainerWithSize<&arr>(10);

  // Setting numbers
  for (size_t i = 0; i < arr @len; ++i) {
    struct Value.Int **elem = ContainerAt<&arr>(i);
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = i;
    *elem = a;
  }

  // Printing and verifying
  int v = 0;
  for (Value **i = BeginContainer<&arr>(); i != EndContainer<&arr>();
       NextIteratorContainer<&arr>(&i)) {
    struct Value.Int *a = *i;
    assert(a->@x == v);
    ++v;
  }
  assert(v == 10);
  printf("Test_At_And_Iterators passed!\n\n");
}

void Test_Array_Empty() {
  printf("Running Test_Array_Empty...\n");
  struct Container.Array arr;
  InitContainerWithSize<&arr>(0);
  assert(EmptyContainer<&arr>() == 1);
  printf("Test_Array_Empty passed!\n\n");
}

void Test_Clear_Container() {
  printf("Running Test_Clear_Container...\n");
  struct Container.Array arr;
  InitContainerWithSize<&arr>(5);
  
  // Fill container
  for (size_t i = 0; i < arr @len; ++i) {
    struct Value.Int **elem = ContainerAt<&arr>(i);
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = i * 10;
    *elem = a;
  }
  
  assert(EmptyContainer<&arr>() == 0);
  ClearContainer<&arr>();
  assert(EmptyContainer<&arr>() == 1);
  printf("Test_Clear_Container passed!\n\n");
}

void Test_Container_Boundaries() {
  printf("Running Test_Container_Boundaries...\n");
  struct Container.Array arr;
  InitContainerWithSize<&arr>(3);
  
  // Test valid access
  struct Value.Int **elem = ContainerAt<&arr>(1);
  struct Value.Int *a = create_spec(Value.Int);
  a->@x = 42;
  *elem = a;
  struct Value.Int *b = *elem;
  assert(b->@x == 42);
  
  // Test invalid access
  assert(ContainerAt<&arr>(3) == NULL);  // Out of bounds
  assert(ContainerAt<&arr>(-1) == NULL); // Invalid index
  
  printf("Test_Container_Boundaries passed!\n\n");
}

void Test_Iterator_Functions() {
  printf("Running Test_Iterator_Functions...\n");
  struct Container.Array arr;
  InitContainerWithSize<&arr>(4);
  
  // Fill container with values
  for (size_t i = 0; i < arr @len; ++i) {
    struct Value.Int **elem = ContainerAt<&arr>(i);
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = i * 2 + 1;
    *elem = a;
  }
  
  // Test Begin and End
  Value **begin = BeginContainer<&arr>();
  Value **end = EndContainer<&arr>();
  assert(begin != end);
  
  // Test iteration
  int expected[] = {1, 3, 5, 7};
  int idx = 0;
  for (Value **it = begin; it != end; NextIteratorContainer<&arr>(&it)) {
    struct Value.Int *v = *it;
    assert(v->@x == expected[idx]);
    idx++;
  }
  assert(idx == 4);
  
  printf("Test_Iterator_Functions passed!\n\n");
}

void Test_Empty_Container_Operations() {
  printf("Running Test_Empty_Container_Operations...\n");
  struct Container.Array arr;
  InitContainerWithSize<&arr>(0);
  
  // All operations on empty container should be safe
  assert(BeginContainer<&arr>() == EndContainer<&arr>());
  assert(ContainerAt<&arr>(0) == NULL);
  ClearContainer<&arr>(); // Should not crash
  
  printf("Test_Empty_Container_Operations passed!\n\n");
}

int main() {
  Test_At_And_Iterators();
  Test_Array_Empty();
  Test_Clear_Container();
  Test_Container_Boundaries();
  Test_Iterator_Functions();
  Test_Empty_Container_Operations();
  
  printf("All tests passed successfully!\n");
  return 0;
}