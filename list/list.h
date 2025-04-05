#ifndef __list__
#define __list__
// list.h

#include "../container/container.h"
#include "../value/value.h"


typedef struct Node {
    Value* val;
    Node* next;
    Node* prev;
};

typedef struct List {
    Node* head;
    Node* tail;
    size_t size;
}

void InitList(List *list);

_Bool ListEmpty(List* list);

Value* ListFront(List* list);

Value* ListBack(List* list);

void ListPopBack(List* list);

void ListPushBack(List* list, Value* val);

void ListPopFront(List* list);

void ListPushFront(List* list, Value* val);

void ListInsert(Node* node, Value* val);

void ListErase(Node* node);

void ListMerge(List* left, List* right);

void ListUnique(List* list);

void ListReverse(List* list);


#endif // __list__
