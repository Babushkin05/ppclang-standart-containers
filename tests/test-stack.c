#include "ppstack.h"
#include "ppcontainer.h"
#include <assert.h>
#include <stdio.h>

Container + < Stack;> ;

// Create specialisation for Value
typedef struct Int {
  int x;
} Int;
Value + < Int;> ;

void Test_Stack_Init_Empty() {
    printf("Running Test_Stack_Init_Empty...\n");
    struct Container.Stack st;
    InitContainer<&st>();
    
    assert(EmptyContainer<&st>() == 1);
    printf("Test_Stack_Init_Empty passed!\n\n");
}

void Test_Stack_Push_Pop() {
    printf("Running Test_Stack_Push_Pop...\n");
    struct Container.Stack st;
    InitContainer<&st>();
    
    // Push elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushContainer<&st>((Value*)a);
    }
    
    assert(EmptyContainer<&st>() == 0);
    
    // Pop elements (should come in reverse order)
    for (int i = 4; i >= 0; i--) {
        struct Value.Int *elem = (struct Value.Int*)TopContainer<&st>();
        assert(elem->@x == i);
        
        elem = (struct Value.Int*)PopContainer<&st>();
        assert(elem->@x == i);
    }
    
    assert(EmptyContainer<&st>() == 1);
    printf("Test_Stack_Push_Pop passed!\n\n");
}

void Test_Stack_Top() {
    printf("Running Test_Stack_Top...\n");
    struct Container.Stack st;
    InitContainer<&st>();
    
    // Push single element
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = 42;
    PushContainer<&st>((Value*)a);
    
    // Test Top without pop
    struct Value.Int *top = (struct Value.Int*)TopContainer<&st>();
    assert(top->@x == 42);
    assert(EmptyContainer<&st>() == 0);
    
    // Push another element
    struct Value.Int *b = create_spec(Value.Int);
    b->@x = 100;
    PushContainer<&st>((Value*)b);
    
    top = (struct Value.Int*)TopContainer<&st>();
    assert(top->@x == 100);
    
    printf("Test_Stack_Top passed!\n\n");
}

void Test_Stack_Clear() {
    printf("Running Test_Stack_Clear...\n");
    struct Container.Stack st;
    InitContainer<&st>();
    
    // Push elements
    for (int i = 0; i < 3; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushContainer<&st>((Value*)a);
    }
    
    assert(EmptyContainer<&st>() == 0);
    ClearContainer<&st>();
    assert(EmptyContainer<&st>() == 1);
    
    // Should be able to push again after clear
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = 99;
    PushContainer<&st>((Value*)a);
    assert(EmptyContainer<&st>() == 0);
    
    printf("Test_Stack_Clear passed!\n\n");
}

void Test_Stack_Empty_Operations() {
    printf("Running Test_Stack_Empty_Operations...\n");
    struct Container.Stack st;
    InitContainer<&st>();
    
    // Top and Pop on empty stack should return NULL
    assert(TopContainer<&st>() == NULL);
    assert(PopContainer<&st>() == NULL);
    
    // Clear empty stack should work
    ClearContainer<&st>();
    assert(EmptyContainer<&st>() == 1);
    
    printf("Test_Stack_Empty_Operations passed!\n\n");
}

void Test_Stack_Order() {
    printf("Running Test_Stack_Order...\n");
    struct Container.Stack st;
    InitContainer<&st>();
    
    // Test LIFO order
    int values[] = {10, 20, 30, 40, 50};
    
    // Push all values
    for (int i = 0; i < 5; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = values[i];
        PushContainer<&st>((Value*)a);
    }
    
    // Pop and verify reverse order
    for (int i = 4; i >= 0; i--) {
        struct Value.Int *elem = (struct Value.Int*)PopContainer<&st>();
        assert(elem->@x == values[i]);
    }
    
    assert(EmptyContainer<&st>() == 1);
    printf("Test_Stack_Order passed!\n\n");
}

int main() {
    Test_Stack_Init_Empty();
    Test_Stack_Push_Pop();
    Test_Stack_Top();
    Test_Stack_Clear();
    Test_Stack_Empty_Operations();
    Test_Stack_Order();
    
    printf("All Stack container tests passed successfully!\n");
    return 0;
}