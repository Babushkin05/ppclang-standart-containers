#include "container.h"
#include "hashmap.h"

Container + < HashMap;>;

void InitContainer<Container.HashMap * container>() {
  HashMap *map = &(container->@);
  InitHashMap(map);
}

void ClearContainer<Container.HashMap * container>() {
  HashMap *map = &(container->@);
  HashMapClear(map);
}

_Bool EmptyContainer<Container.HashMap * container>() {
  HashMap *map = &(container->@);
  return HashMapEmpty(map);
}

void InsertKeyValueContainer<Container.HashMap * container>(Value *key, Value *val) {
  HashMap *map = &(container->@);
  HashMapInsert(map, key, val);
}

_Bool ContainsContainer<Container.HashMap * container>(Value *val) {
  HashMap *map = &(container->@);
  return HashMapContains(map, val);
}

Value *ContainerValueByKey<Container.HashMap * container>(Value *key) {
    HashMap *map = &(container->@);
    return HashMapAt(map, key);
}

void EraseContainer<Container.HashMap * container>(Value *val) {
  HashMap *map = &(container->@);
  HashMapErase(map, val);
}

