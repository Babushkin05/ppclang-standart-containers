#include "ppcontainer.h"
#include "pphashset.h"

Container + < HashSet;>;

void InitContainer<Container.HashSet * container>() {
  HashSet *set = &(container->@);
  InitHashSet(set);
}

void ClearContainer<Container.HashSet * container>() {
  HashSet *set = &(container->@);
  HashSetClear(set);
}

_Bool EmptyContainer<Container.HashSet * container>() {
  HashSet *set = &(container->@);
  return HashSetEmpty(set);
}

void InsertContainer<Container.HashSet * container>(Value *val) {
  HashSet *set = &(container->@);
  HashSetInsert(set, val);
}

_Bool ContainsContainer<Container.HashSet * container>(Value *val) {
  HashSet *set = &(container->@);
  return HashSetContains(set, val);
}

void EraseContainer<Container.HashSet * container>(Value *val) {
  HashSet *set = &(container->@);
  HashSetErase(set, val);
}
