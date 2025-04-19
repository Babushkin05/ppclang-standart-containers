#include "vector.h"
#include "container.h"
#include <assert.h>
#include <stdio.h>

Container + < Vector;> ;

// Create specialisation for Value
typedef struct Int {
  int x;
} Int;
Value + < Int;> ;

void Test_Vector_Init_Empty() {
    printf("Running Test_Vector_Init_Empty...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(0);
    
    assert(EmptyContainer<&vec>() == 1);
    assert(BeginContainer<&vec>() == EndContainer<&vec>());
    
    printf("Test_Vector_Init_Empty passed!\n\n");
}

void Test_Vector_Init_With_Size() {
    printf("Running Test_Vector_Init_With_Size...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(5);
    
    assert(EmptyContainer<&vec>() == 0);
    assert(vec.@len == 5);
    assert(vec.@cap >= 5);
    
    printf("Test_Vector_Init_With_Size passed!\n\n");
}

void Test_Vector_Push_Pop() {
    printf("Running Test_Vector_Push_Pop...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(0);
    
    // Push elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&vec>((Value*)a);
    }
    
    assert(vec.@len == 5);
    assert(EmptyContainer<&vec>() == 0);
    
    // Verify pushed elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int *elem = (struct Value.Int*)*ContainerAt<&vec>(i);
        assert(elem->@x == i);
    }
    
    // Pop elements
    for (int i = 4; i >= 0; i--) {
        struct Value.Int *elem = (struct Value.Int*)*ContainerAt<&vec>(vec.@len-1);
        assert(elem->@x == i);
        PopBackContainer<&vec>();
    }
    
    assert(vec.@len == 0);
    assert(EmptyContainer<&vec>() == 1);
    
    printf("Test_Vector_Push_Pop passed!\n\n");
}

void Test_Vector_Clear() {
    printf("Running Test_Vector_Clear...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(3);
    
    // Fill vector
    for (int i = 0; i < 3; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        *ContainerAt<&vec>(i) = (Value*)a;
    }
    
    assert(EmptyContainer<&vec>() == 0);
    ClearContainer<&vec>();
    assert(EmptyContainer<&vec>() == 1);
    assert(vec.@len == 0);
    
    printf("Test_Vector_Clear passed!\n\n");
}

void Test_Vector_Iterators() {
    printf("Running Test_Vector_Iterators...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(4);
    
    // Fill vector
    for (int i = 0; i < 4; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i * 2;
        *ContainerAt<&vec>(i) = (Value*)a;
    }
    
    // Test iteration
    int expected[] = {0, 2, 4, 6};
    int idx = 0;
    
    for (Value **it = BeginContainer<&vec>(); it != EndContainer<&vec>(); 
         NextIteratorContainer<&vec>(&it)) {
        struct Value.Int *elem = (struct Value.Int*)*it;
        assert(elem->@x == expected[idx]);
        idx++;
    }
    assert(idx == 4);
    
    printf("Test_Vector_Iterators passed!\n\n");
}

void Test_Vector_At_Boundaries() {
    printf("Running Test_Vector_At_Boundaries...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(2);
    
    // Valid access
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = 10;
    *ContainerAt<&vec>(0) = (Value*)a;
    
    struct Value.Int *b = create_spec(Value.Int);
    b->@x = 20;
    *ContainerAt<&vec>(1) = (Value*)b;
    
    // Invalid access
    assert(ContainerAt<&vec>(2) == NULL);
    assert(ContainerAt<&vec>(-1) == NULL);
    
    printf("Test_Vector_At_Boundaries passed!\n\n");
}

void Test_Vector_Growth() {
    printf("Running Test_Vector_Growth...\n");
    struct Container.Vector vec;
    InitContainerWithSize<&vec>(0);
    
    size_t initial_cap = vec.@cap;
    
    // Push elements beyond initial capacity
    for (int i = 0; i < 20; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&vec>((Value*)a);
    }
    
    assert(vec.@len == 20);
    assert(vec.@cap > initial_cap);
    
    // Verify all elements
    for (int i = 0; i < 20; i++) {
        struct Value.Int *elem = (struct Value.Int*)*ContainerAt<&vec>(i);
        assert(elem->@x == i);
    }
    
    printf("Test_Vector_Growth passed!\n\n");
}

int main() {
    Test_Vector_Init_Empty();
    Test_Vector_Init_With_Size();
    Test_Vector_Push_Pop();
    Test_Vector_Clear();
    Test_Vector_Iterators();
    Test_Vector_At_Boundaries();
    Test_Vector_Growth();
    
    printf("All Vector container tests passed successfully!\n");
    return 0;
}