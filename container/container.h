#ifndef __container__
#define __container__

/**
 * @file container.h
 * @brief Generic container interface for storing Value objects
 * 
 * This header defines an abstract interface for various container types
 * (stacks, queues, lists, etc.) that can store Value objects.
 * Implementations should provide concrete versions of these operations.
 */

#include "../value/value.c"

/**
 * @struct Container
 * @brief Base structure for all container implementations
 * 
 * This serves as a generic container type that can be implemented
 * as various concrete data structures (array, list, tree, etc.).
 * The actual implementation details should be defined in derived types.
 */
typedef struct Container {
    // Implementation-specific fields should be added in concrete containers
} Container;

// -------------------------------
// Basic Container Operations
// -------------------------------

/**
 * @brief Initialize a container with default settings
 * @param container Pointer to the container to initialize
 */
void InitContainer(Container *container);

/**
 * @brief Initialize a container with specified initial capacity
 * @param container Pointer to the container to initialize
 * @param size Initial capacity of the container
 */
void InitContainerWithSize(Container *container, size_t size);

/**
 * @brief Remove all elements from the container
 * @param container Pointer to the container to clear
 */
void ClearContainer(Container *container);

/**
 * @brief Check if container contains no elements
 * @param container Pointer to the container to check
 * @return 1 if container is empty, 0 otherwise
 */
_Bool EmptyContainer(Container *container);

// -------------------------------
// Element Addition Operations
// -------------------------------

/**
 * @brief Add element to container (implementation-specific)
 * @param container Pointer to the container
 * @param val Value to add (container decides where to place it)
 */
void PushContainer(Container *container, Value *val);

/**
 * @brief Add element to the end of container
 * @param container Pointer to the container
 * @param val Value to add at the back
 */
void PushBackContainer(Container *container, Value *val);

/**
 * @brief Add element to the beginning of container
 * @param container Pointer to the container
 * @param val Value to add at the front
 */
void PushFrontContainer(Container *container, Value *val);

// -------------------------------
// Element Removal Operations
// -------------------------------

/**
 * @brief Remove and return element (implementation-specific)
 * @param container Pointer to the container
 * @return Removed value, or NULL if container is empty
 */
Value *PopContainer(Container *container);

/**
 * @brief Remove element from the end of container
 * @param container Pointer to the container
 */
void PopBackContainer(Container *container);

/**
 * @brief Remove element from the beginning of container
 * @param container Pointer to the container
 */
void PopFrontContainer(Container *container);

// -------------------------------
// Element Access Operations
// -------------------------------

/**
 * @brief Get top element without removal (for stack-like containers)
 * @param container Pointer to the container
 * @return Top value, or NULL if container is empty
 */
Value *TopContainer(Container *container);

/**
 * @brief Get first element in container
 * @param container Pointer to the container
 * @return Front value, or NULL if container is empty
 */
Value *FrontContainer(Container *container);

/**
 * @brief Get last element in container
 * @param container Pointer to the container
 * @return Back value, or NULL if container is empty
 */
Value *BackContainer(Container *container);

// -------------------------------
// Special Container Operations
// -------------------------------

/**
 * @brief Insert element at appropriate position (for ordered containers)
 * @param container Pointer to the container
 * @param val Value to insert
 */
void InsertContainer(Container *container, Value *val);

/**
 * @brief Check if container contains specific value
 * @param container Pointer to the container
 * @param val Value to search for
 * @return 1 if value found, 0 otherwise
 */
_Bool ContainsContainer(Container *container, Value *val);

/**
 * @brief Get element by index (for indexable containers)
 * @param container Pointer to the container
 * @param index Position to access
 * @return Value at index, or NULL if out of bounds
 */
Value *ContainerValueByKey(Container *container, int index);

/**
 * @brief Remove specific value from container
 * @param container Pointer to the container
 * @param val Value to remove
 */
void EraseContainer(Container *container, Value *val);

// -------------------------------
// Iterator Operations
// -------------------------------

/**
 * @brief Get iterator to element at specific index
 * @param container Pointer to the container
 * @param index Position to access
 * @return Iterator to element at index, or NULL if invalid
 */
Value **ContainerAt(Container *container, int index);

/**
 * @brief Get iterator to first element
 * @param container Pointer to the container
 * @return Iterator to beginning, or NULL if empty
 */
Value **BeginContainer(Container *container);

/**
 * @brief Get iterator to position after last element
 * @param container Pointer to the container
 * @return End iterator
 */
Value **EndContainer(Container *container);

/**
 * @brief Advance iterator to next element
 * @param container Pointer to the container
 * @param iter Pointer to iterator to advance (will be modified)
 */
void NextIteratorContainer(Container *container, Value ***iter);

#endif // __container__