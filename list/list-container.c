#include "../container/container.h"
#include "list.h"

Container + <List;>;

void InitContainer<Container.List * container>() {
  List *list = &(container->@);
  InitList(list);
}

void ClearContainer<Container.List * container>() {
  List *list = &(container->@);
  ListClear(list);
}

_Bool EmptyContainer<Container.List * container>() {
  List *list = &(container->@);
  return ListEmpty(list);
}

void PushBackContainer<Container.List * container>(Value *val) {
  List *list = &(container->@);
  ListPushBack(list, val);
}

void PopBackContainer<Container.List * container>() {
  List *list = &(container->@);
  ListPopBack(list);
}

void PushFrontContainer<Container.List * container>(Value *val) {
  List *list = &(container->@);
  ListPushFront(list, val);
}

void PopFrontContainer<Container.List * container>() {
  List *list = &(container->@);
  ListPopFront(list);
}

Value *FrontContainer<Container.List * container>() {
  List *list = &(container->@);
  return ListFront(list);
}

Value *BackContainer<Container.List * container>() {
  List *list = &(container->@);
  return ListBack(list);
}