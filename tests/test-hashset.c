#include "hashset.h"
#include "container.h"
#include "int.h"
#include <assert.h>
#include <stdio.h>

Container + <HashSet;>;

Value + <Int;>;

void Test_HashSet_Init_Empty() {
    printf("Running Test_HashSet_Init_Empty...\n");
    struct Container.HashSet set;
    InitContainer<&set>();

    assert(EmptyContainer<&set>() == 1);
    printf("Test_HashSet_Init_Empty passed!\n\n");
}

void Test_HashSet_Insert_Contains() {
    printf("Running Test_HashSet_Insert_Contains...\n");
    struct Container.HashSet set;
    InitContainer<&set>();
    
    // Insert elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        InsertContainer<&set>(a);
    }
    
    // Check contains
    for (int i = 0; i < 5; i++) {
        struct Value.Int* temp = create_spec(Value.Int);
        temp->@x = i;
        assert(ContainsContainer<&set>(temp) == 1);
    }
    
    // Check non-existing
    struct Value.Int* temp = create_spec(Value.Int);
    temp->@x = 100;
    assert(ContainsContainer<&set>(temp) == 0);
    
    printf("Test_HashSet_Insert_Contains passed!\n\n");
}

void Test_HashSet_Erase() {
    printf("Running Test_HashSet_Erase...\n");
    struct Container.HashSet set;
    InitContainer<&set>();
    
    // Insert elements
    for (int i = 0; i < 10; i++) {
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        InsertContainer<&set>((Value*)a);
    }
    
    // Erase odd numbers
    for (int i = 1; i < 10; i += 2) {
        struct Value.Int* temp = create_spec(Value.Int);
        temp->@x = i;
        EraseContainer<&set>((Value*)temp);
    }
    
    // Verify
    for (int i = 0; i < 10; i++) {
        struct Value.Int* temp = create_spec(Value.Int);
        temp->@x = i;
        if (i % 2 == 0) {
            assert(ContainsContainer<&set>((Value*)temp) == 1);
        } else {
            assert(ContainsContainer<&set>((Value*)temp) == 0);
        }
    }
    
    printf("Test_HashSet_Erase passed!\n\n");
}

void Test_HashSet_Clear() {
    printf("Running Test_HashSet_Clear...\n");
    struct Container.HashSet set;
    InitContainer<&set>();
    
    // Insert elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        InsertContainer<&set>((Value*)a);
    }
    
    assert(EmptyContainer<&set>() == 0);
    ClearContainer<&set>();
    assert(EmptyContainer<&set>() == 1);
    
    // Should be able to insert again after clear
    struct Value.Int* a = create_spec(Value.Int);
    a->@x = 42;
    InsertContainer<&set>((Value*)a);
    assert(EmptyContainer<&set>() == 0);
    
    printf("Test_HashSet_Clear passed!\n\n");
}

void Test_HashSet_Duplicates() {
    printf("Running Test_HashSet_Duplicates...\n");
    struct Container.HashSet set;
    InitContainer<&set>();
    
    struct Value.Int* a = create_spec(Value.Int);
    a->@x = 10;
    
    // Insert same element multiple times
    InsertContainer<&set>(a);
    InsertContainer<&set>(a);
    InsertContainer<&set>(a);
    // Should contain only one instance
    assert(ContainsContainer<&set>(a) == 1);
    // Erase once should remove it completely
    EraseContainer<&set>(a);
    assert(ContainsContainer<&set>(a) == 0);
    printf("Test_HashSet_Duplicates passed!\n\n");
}

void Test_HashSet_Rehash() {
    printf("Running Test_HashSet_Rehash...\n");
    struct Container.HashSet set;
    InitContainer<&set>();
    
    // Insert many elements to trigger rehash
    for (int i = 0; i < 1000; i++) {
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        InsertContainer<&set>((Value*)a);
    }
    
    // Verify all inserted
    for (int i = 0; i < 1000; i++) {
        struct Value.Int* temp = create_spec(Value.Int);
        temp->@x = i;
        assert(ContainsContainer<&set>((Value*)temp) == 1);
    }
    
    printf("Test_HashSet_Rehash passed!\n\n");
}

int main() {    
    Test_HashSet_Init_Empty();
    Test_HashSet_Insert_Contains();
    Test_HashSet_Erase();
    Test_HashSet_Clear();
    Test_HashSet_Duplicates();
    Test_HashSet_Rehash();
    
    printf("All HashSet container tests passed successfully!\n");
    return 0;
}