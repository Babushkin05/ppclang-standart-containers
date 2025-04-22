#include "pplist.h"
#include "ppcontainer.h"
#include <assert.h>
#include <stdio.h>

Container + <List;>;

// Create specialisation for Value
typedef struct Int {
  int x;
} Int;
Value + <Int;>;

void Test_List_Init_Empty() {
    printf("Running Test_List_Init_Empty...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    assert(EmptyContainer<&lst>() == 1);
    printf("Test_List_Init_Empty passed!\n\n");
}

void Test_List_Push_Pop_Front() {
    printf("Running Test_List_Push_Pop_Front...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    // Push front elements
    for (int i = 0; i < 3; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushFrontContainer<&lst>((Value*)a);
    }
    
    assert(EmptyContainer<&lst>() == 0);
    
    // Pop front elements (should come in reverse order)
    for (int i = 2; i >= 0; i--) {
        struct Value.Int *front = (struct Value.Int*)FrontContainer<&lst>();
        assert(front->@x == i);
        PopFrontContainer<&lst>();
    }
    
    assert(EmptyContainer<&lst>() == 1);
    printf("Test_List_Push_Pop_Front passed!\n\n");
}

void Test_List_Push_Pop_Back() {
    printf("Running Test_List_Push_Pop_Back...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    // Push back elements
    for (int i = 0; i < 3; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&lst>((Value*)a);
    }
    
    assert(EmptyContainer<&lst>() == 0);
    
    // Pop back elements (should come in same order)
    for (int i = 2; i >= 0; i--) {
        struct Value.Int *back = (struct Value.Int*)BackContainer<&lst>();
        assert(back->@x == i);
        PopBackContainer<&lst>();
    }
    
    assert(EmptyContainer<&lst>() == 1);
    printf("Test_List_Push_Pop_Back passed!\n\n");
}

void Test_List_Front_Back() {
    printf("Running Test_List_Front_Back...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    // Push front and back
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = 10;
    PushFrontContainer<&lst>((Value*)a);
    
    struct Value.Int *b = create_spec(Value.Int);
    b->@x = 20;
    PushBackContainer<&lst>((Value*)b);
    
    struct Value.Int *c = create_spec(Value.Int);
    c->@x = 30;
    PushFrontContainer<&lst>((Value*)c);
    
    // Verify front and back
    struct Value.Int* f = FrontContainer<&lst>();
    struct Value.Int *bk = BackContainer<&lst>();
    assert(f->@x == 30);
    assert(bk->@x == 20);
    
    printf("Test_List_Front_Back passed!\n\n");
}

void Test_List_Clear() {
    printf("Running Test_List_Clear...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    // Push elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&lst>((Value*)a);
    }
    
    assert(EmptyContainer<&lst>() == 0);
    ClearContainer<&lst>();
    assert(EmptyContainer<&lst>() == 1);
    
    // Should be able to push again after clear
    struct Value.Int *a = create_spec(Value.Int);
    a->@x = 100;
    PushFrontContainer<&lst>((Value*)a);
    assert(EmptyContainer<&lst>() == 0);
    
    printf("Test_List_Clear passed!\n\n");
}

void Test_List_Empty_Operations() {
    printf("Running Test_List_Empty_Operations...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    // Operations on empty list
    assert(FrontContainer<&lst>() == NULL);
    assert(BackContainer<&lst>() == NULL);
    
    // Should not crash
    PopFrontContainer<&lst>();
    PopBackContainer<&lst>();
    ClearContainer<&lst>();
    
    printf("Test_List_Empty_Operations passed!\n\n");
}

void Test_List_Mixed_Operations() {
    printf("Running Test_List_Mixed_Operations...\n");
    struct Container.List lst;
    InitContainer<&lst>();
    
    // Mixed push front/back
    for (int i = 0; i < 5; i++) {
        struct Value.Int *a = create_spec(Value.Int);
        a->@x = i;
        if (i % 2 == 0) {
            PushFrontContainer<&lst>((Value*)a);
        } else {
            PushBackContainer<&lst>((Value*)a);
        }
    }
    
    // Expected order: 4, 2, 0, 1, 3
    int expected[] = {4, 2, 0, 1, 3};
    int idx = 0;
    
    // Verify by popping front
    while (!EmptyContainer<&lst>()) {
        struct Value.Int *front = (struct Value.Int*)FrontContainer<&lst>();
        assert(front->@x == expected[idx++]);
        PopFrontContainer<&lst>();
    }
    
    printf("Test_List_Mixed_Operations passed!\n\n");
}

int main() {
    Test_List_Init_Empty();
    Test_List_Push_Pop_Front();
    Test_List_Push_Pop_Back();
    Test_List_Front_Back();
    Test_List_Clear();
    Test_List_Empty_Operations();
    Test_List_Mixed_Operations();
    
    printf("All List container tests passed successfully!\n");
    return 0;
}