#ifndef DATA_STRUCTURES_LINKED_LIST_H_
#define DATA_STRUCTURES_LINKED_LIST_H_

#include <stddef.h>

typedef struct node_t {
  int value;
  struct node_t *prev;
  struct node_t *next;
} node_t;

typedef struct linked_list_t {
  node_t *head;
  node_t *tail;
  size_t len;
} linked_list_t;

/**
 * Allocates a new linked list.
 *
 * @return A pointer to the newly created linked list.
 */
linked_list_t *create_list();

/**
 * Destroys a linked list and frees the memory allocated for it.
 *
 * This function deallocates all the nodes in the linked list and frees the
 * memory occupied by them. After calling this function, the linked list will be
 * empty and the memory previously used by it will be released.
 *
 * @param list A pointer to the linked list to be destroyed.
 */
void destroy_list(linked_list_t *list);

/**
 * Creates a new node with the given value.
 *
 * This function allocates a new node with the specified value and returns a
 * pointer to it.
 *
 * @param value The value to be stored in the node.
 * @return A pointer to the newly created node.
 */
node_t *create_node(int value);

/**
 * Destroys a node and frees the memory allocated for it.
 *
 * This function deallocates the memory occupied by the given node and frees it.
 *
 * @param node A pointer to the node to be destroyed.
 */
void destroy_node(node_t *node);

/**
 * Adds a new node to the end of the linked list.
 *
 * @param list A pointer to the linked list.
 * @param node A pointer to the node to be added.
 * @return non-negative value if the node was successfully added, -1 otherwise.
 */
int add_last(linked_list_t *list, node_t *node);

/**
 * Removes and returns the last node from the linked list.
 *
 * @param list A pointer to the linked list.
 * @return A pointer to the last node in the linked list, or NULL if the list is
 * empty.
 */
node_t *pop_last(linked_list_t *list);

/**
 * Adds a node to the beginning of the linked list.
 *
 * @param list The linked list to add the node to.
 * @param node The node to be added.
 * @return non-negative value if the node was successfully added, -1 otherwise.
 */
int add_first(linked_list_t *list, node_t *node);

/**
 * Removes and returns the first node from the linked list.
 *
 * @param list A pointer to the linked list.
 * @return A pointer to the first node in the linked list, or NULL if the list
 * is empty.
 */
node_t *pop_first(linked_list_t *list);

/**
 * Retrieves the node at the specified index in the linked list.
 *
 * @param list A pointer to the linked list.
 * @param index The index of the node to retrieve.
 * @return A pointer to the node at the specified index, or NULL if the index is
 * out of bounds.
 */
node_t *get_node(linked_list_t *list, size_t index);

/**
 * Removes and returns the node at the specified index in the linked list.
 *
 * @param list A pointer to the linked list.
 * @param index The index of the node to remove.
 * @return A pointer to the removed node, or NULL if the index is out of bounds,
 * or the list is empty.
 */
node_t *pop_node(linked_list_t *list, size_t index);

/**
 * Inserts a node at the specified index in the linked list.
 *
 * @param list A pointer to the linked list.
 * @param index The index at which to insert the node.
 * @param node A pointer to the node to insert.
 */
void insert_node(linked_list_t *list, size_t index, node_t *node);

#endif // DATA_STRUCTURES_LINKED_LIST_H_
