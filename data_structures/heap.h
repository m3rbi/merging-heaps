#ifndef DATA_STRUCTURES_HEAP_H_
#define DATA_STRUCTURES_HEAP_H_

#include "linked_list.h"

#include <stdbool.h>

typedef struct min_heap_t {
  linked_list_t *list;
  bool is_sorted;
} min_heap_t;

/**
 * Builds a min heap from a linked list.
 *
 * This function takes a pointer to a linked list and constructs a min heap from
 * its elements. The new heap is constructed in-place, meaning that the original
 * linked list is modified.
 *
 * @param list A pointer to the linked list.
 * @param is_sorted A boolean flag indicating whether the original list is
 * sorted. If true, a more efficient build algorithm is used.
 * @return The constructed min heap.
 */
min_heap_t build_min_heap(linked_list_t *list, bool is_sorted);

/**
 * Extracts the minimum element from the min heap.
 *
 * This function removes and returns the minimum element from the given min
 * heap. The min heap is modified accordingly to maintain its heap property.
 *
 * @param heap The min heap from which to extract the minimum element.
 * @return A pointer to the minimum element in the min heap, or NULL if the heap
 * is empty.
 */
node_t *min_heap_extract_min(min_heap_t *heap);

/**
 * Inserts a new value into the min heap.
 *
 * @param heap The min heap to insert the value into.
 * @param value The value to be inserted into the min heap.
 */
void min_heap_insert(min_heap_t *heap, int value);

/**
 * Merges two min heaps into a single min heap.
 *
 * This function takes two min heaps, `heap_a` and `heap_b`, and merges them
 * into a single min heap. The resulting min heap will contain all the elements
 * from both `heap_a` and `heap_b`. The original min heaps are modified
 * accordingly, heap `heap_b` will be empty after the merge, and heap `heap_a`
 * will contain the merged elements. NOTE: the original list of `heap_a` is
 * invalidated, and freed.
 *
 * @param heap_a The first min heap to be merged.
 * @param heap_b The second min heap to be merged.
 */
void union_min_heaps(min_heap_t *heap_a, min_heap_t *heap_b);

/**
 * Sorts a linked list in ascending order using the min heap sort algorithm.
 *
 * @param list A pointer to a pointer to the linked list to be sorted.
 * @param is_sorted A boolean flag indicating whether the original list is
 * sorted.
 */
void min_heap_sort(linked_list_t **list, bool is_sorted);

#endif // DATA_STRUCTURES_HEAP_H_