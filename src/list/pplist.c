#include "pplist.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize an empty list
void InitList(List *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

// Check if list is empty
_Bool ListEmpty(List *list) { return list->size == 0; }

// Clear the list and free all memory
void ListClear(List *list) {
  if (!list)
    return;

  Node *current = list->head;
  while (current) {
    Node *next = current->next;
    free(current->val); 
    free(current);      
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

// Get the first element of the list
Value *ListFront(List *list) {
  if (ListEmpty(list)) {
    fprintf(stderr, "Error: list is empty\n");
    return NULL;
  }
  return list->head->val;
}

// Get the last element of the list
Value *ListBack(List *list) {
  if (ListEmpty(list)) {
    fprintf(stderr, "Error: list is empty\n");
    return NULL;
  }
  return list->tail->val;
}

// Remove the last element from the list
void ListPopBack(List *list) {
  if (ListEmpty(list)) {
    fprintf(stderr, "Error: list is empty\n");
    return;
  }

  Node *toRemove = list->tail;
  if (list->size == 1) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    list->tail = toRemove->prev;
    list->tail->next = NULL;
  }

  free(toRemove);
  list->size--;
}

// Add an element to the end of the list
void ListPushBack(List *list, Value *val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Error: memory allocation failed\n");
    return;
  }

  newNode->val = val;
  newNode->next = NULL;
  newNode->prev = list->tail;

  if (ListEmpty(list)) {
    list->head = newNode;
  } else {
    list->tail->next = newNode;
  }

  list->tail = newNode;
  list->size++;
}

// Remove the first element from the list
void ListPopFront(List *list) {
  if (ListEmpty(list)) {
    fprintf(stderr, "Error: list is empty\n");
    return;
  }

  Node *toRemove = list->head;
  if (list->size == 1) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    list->head = toRemove->next;
    list->head->prev = NULL;
  }

  free(toRemove->val);
  free(toRemove);
  list->size--;
}

// Add an element to the beginning of the list
void ListPushFront(List *list, Value *val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Error: memory allocation failed\n");
    return;
  }

  newNode->val = val;
  newNode->prev = NULL;
  newNode->next = list->head;

  if (ListEmpty(list)) {
    list->tail = newNode;
  } else {
    list->head->prev = newNode;
  }

  list->head = newNode;
  list->size++;
}

// Insert an element before the specified node
void ListInsert(List *list, Node *node, Value *val) {
  if (!list || !node)
    return;

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Error: memory allocation failed\n");
    return;
  }

  newNode->val = val;
  newNode->prev = node->prev;
  newNode->next = node;

  if (node->prev) {
    node->prev->next = newNode;
  } else {
    list->head = newNode;
  }

  node->prev = newNode;
  list->size++;
}

// Remove the specified node from the list
void ListErase(List *list, Node *node) {
  if (!list || !node)
    return;

  if (node->prev) {
    node->prev->next = node->next;
  } else {
    // Removing the head
    list->head = node->next;
  }

  if (node->next) {
    node->next->prev = node->prev;
  } else {
    // Removing the tail
    list->tail = node->prev;
  }

  free(node->val);
  free(node);
  list->size--;
}

// Merge two lists (move elements from right to left)
void ListMerge(List *left, List *right) {
  if (!left || !right || ListEmpty(right))
    return;

  if (ListEmpty(left)) {
    left->head = right->head;
    left->tail = right->tail;
  } else {
    left->tail->next = right->head;
    if (right->head) {
      right->head->prev = left->tail;
    }
    left->tail = right->tail;
  }

  left->size += right->size;

  // Clear right (but don't free elements)
  right->head = NULL;
  right->tail = NULL;
  right->size = 0;
}

// Reverse the list
void ListReverse(List *list) {
  if (ListEmpty(list) || list->size == 1)
    return;

  Node *current = list->head;
  list->head = list->tail;
  list->tail = current;

  while (current) {
    Node *next = current->next;
    current->next = current->prev;
    current->prev = next;
    current = next;
  }
}