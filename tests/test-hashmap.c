#include "hashmap.h"
#include "container.h"
#include "int.h"
#include "string.h"
#include <assert.h>
#include <stdio.h>

Container + <HashMap;>;

Value + <Int;>;

Value + <String;>;

void Test_HashMap_Init_Empty() {
    printf("Running Test_HashMap_Init_Empty...\n");
    struct Container.HashMap map;
    InitContainer<&map>();
    
    assert(EmptyContainer<&map>() == 1);
    printf("Test_HashMap_Init_Empty passed!\n\n");
}

void Test_HashMap_Insert_Lookup() {
    printf("Running Test_HashMap_Insert_Lookup...\n");
    struct Container.HashMap map;
    InitContainer<&map>();
    
    // Insert key-value pairs
    for (int i = 0; i < 5; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        
        struct Value.String* val = create_spec(Value.String);
        sprintf(val->@value, "Value%d", i);
        
        InsertKeyValueContainer<&map>((Value*)key, (Value*)val);
    }
    
    // Lookup values
    for (int i = 0; i < 5; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        
        struct Value.String* val = (struct Value.String*)ContainerValueByKey<&map>((Value*)key);
        assert(val != NULL);
        
        char expected[20];
        sprintf(expected, "Value%d", i);
        assert(strcmp(val->@value, expected) == 0);
    }
    
    printf("Test_HashMap_Insert_Lookup passed!\n\n");
}

void Test_HashMap_Contains_Erase() {
    printf("Running Test_HashMap_Contains_Erase...\n");
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
            assert(ContainsContainer<&map>(key) == 1);
            EraseContainer<&map>(key);
            assert(ContainsContainer<&map>((Value*)key) == 0);
        }
    }
    
    // Verify remaining even keys
    for (int i = 0; i < 10; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        
        if (i % 2 == 0) {
            assert(ContainsContainer<&map>((Value*)key) == 1);
            struct Value.String* val = (struct Value.String*)ContainerValueByKey<&map>((Value*)key);
            assert(val != NULL);
        } else {
            assert(ContainsContainer<&map>((Value*)key) == 0);
            assert(ContainerValueByKey<&map>((Value*)key) == NULL);
        }
    }
    
    printf("Test_HashMap_Contains_Erase passed!\n\n");
}

void Test_HashMap_Clear() {
    printf("Running Test_HashMap_Clear...\n");
    struct Container.HashMap map;
    InitContainer<&map>();
    
    // Insert elements
    for (int i = 0; i < 5; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        
        struct Value.String* val = create_spec(Value.String);
        sprintf(val->@value, "Test%d", i);
        
        InsertKeyValueContainer<&map>((Value*)key, (Value*)val);
    }
    
    assert(EmptyContainer<&map>() == 0);
    ClearContainer<&map>();
    assert(EmptyContainer<&map>() == 1);
    
    // Verify no elements remain
    for (int i = 0; i < 5; i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = i;
        assert(ContainsContainer<&map>((Value*)key) == 0);
    }
    
    printf("Test_HashMap_Clear passed!\n\n");
}

void Test_HashMap_Update_Values() {
    printf("Running Test_HashMap_Update_Values...\n");
    struct Container.HashMap map;
    InitContainer<&map>();
    
    // Insert initial value
    struct Value.Int* key = create_spec(Value.Int);
    key->@x = 42;
    
    struct Value.String* val1 = create_spec(Value.String);
    strcpy(val1->@value, "First");
    InsertKeyValueContainer<&map>((Value*)key, (Value*)val1);
    // Update value
    struct Value.String* val2 = create_spec(Value.String);
    strcpy(val2->@value, "Second");
    InsertKeyValueContainer<&map>((Value*)key, (Value*)val2);
    // Verify update
    struct Value.String* result = ContainerValueByKey<&map>((Value*)key);
        printf("%s\n", result->@value);
    assert(strcmp(result->@value, "Second") == 0);
    
    printf("Test_HashMap_Update_Values passed!\n\n");
}

void Test_HashMap_Collisions() {
    printf("Running Test_HashMap_Collisions...\n");
    struct Container.HashMap map;
    InitContainer<&map>();
    
    // Create keys that may collide (using simple hash for test)
    int keys[] = {1, 17, 33, 49}; // These may collide with table size 16
    
    for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = keys[i];
        
        struct Value.String* val = create_spec(Value.String);
        sprintf(val->@value, "Collision%d", (int)i);
        
        InsertKeyValueContainer<&map>((Value*)key, (Value*)val);
    }
    
    // Verify all keys are accessible
    for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        struct Value.Int* key = create_spec(Value.Int);
        key->@x = keys[i];
        
        assert(ContainsContainer<&map>((Value*)key) == 1);
        struct Value.String* val = (struct Value.String*)ContainerValueByKey<&map>((Value*)key);
        assert(val != NULL);
    }
    
    printf("Test_HashMap_Collisions passed!\n\n");
}

int main() {
    Test_HashMap_Init_Empty();
    Test_HashMap_Insert_Lookup();
    Test_HashMap_Contains_Erase();
    Test_HashMap_Clear();
    Test_HashMap_Update_Values();
    Test_HashMap_Collisions();
    
    printf("All HashMap container tests passed successfully!\n");
    return 0;
}