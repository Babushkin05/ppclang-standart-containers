#ifndef __list__
#define __list__
// list.h

#include "container.h"
#include "value.h"

typedef struct Node {
  Value *val;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  size_t size;
} List;

void InitList(List *list);

_Bool ListEmpty(List *list);

void ListClear(List *list);

Value *ListFront(List *list);

Value *ListBack(List *list);

void ListPopBack(List *list);

void ListPushBack(List *list, Value *val);

void ListPopFront(List *list);

void ListPushFront(List *list, Value *val);

void ListInsert(List *list, Node *node, Value *val);

void ListErase(List *list, Node *node);

void ListMerge(List *left, List *right);

void ListReverse(List *list);

#endif // __list__
