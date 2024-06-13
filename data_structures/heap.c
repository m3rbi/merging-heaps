#include "heap.h"
#include "linked_list.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * Returns the index of the left child of the element at index `i` in the heap.
 *
 * @param i The index of the element in the heap.
 * @return The index of the left child of the element at index `i`.
 */
size_t heap_left(size_t i) { return 2 * i + 1; }

/**
 * Returns the index of the right child of the element at index `i` in the heap.
 *
 * @param i The index of the element in the heap.
 * @return The index of the right child of the element at index `i`.
 */
size_t heap_right(size_t i) { return 2 * i + 2; }

/**
 * Performs the min heapify operation on the given heap starting from the
 * specified index.
 *
 * @param heap The min heap to be heapified.
 * @param index The index from which to start the heapify operation.
 */
void min_heapify(min_heap_t *heap, size_t index) {
  if (!heap || !heap->list || index >= heap->list->len) {
    return;
  }

  size_t left = heap_left(index);
  size_t right = heap_right(index);
  size_t smallest = index;

  node_t *current_node = get_node(heap->list, index);
  if (!current_node) {
    return;
  }
  node_t *smallest_node = current_node;

  if (left < heap->list->len) {
    node_t *left_node = get_node(heap->list, left);
    if (left_node && left_node->value < current_node->value) {
      smallest = left;
      smallest_node = left_node;
    }
  }

  if (right < heap->list->len) {
    node_t *right_node = get_node(heap->list, right);
    if (right_node && right_node->value < smallest_node->value) {
      smallest = right;
      smallest_node = right_node;
    }
  }

  if (smallest == index) {
    return;
  }

  // The original pointers weren't through pop, therfore we're not
  // leaking any memory by doing this.
  smallest_node = pop_node(heap->list, smallest);
  current_node = pop_node(heap->list, index);

  insert_node(heap->list, index, smallest_node);
  insert_node(heap->list, smallest, current_node);

  min_heapify(heap, smallest);
}

/**
 * Decreases the key value of a node in a min heap, and modifies the heap
 * accordingly.
 *
 * @param heap The min heap.
 * @param index The index of the node whose key needs to be decreased.
 * @param key The new key value for the node.
 */
void min_heap_decrease_key(min_heap_t *heap, size_t index, int key) {
  if (!heap || !heap->list || index >= heap->list->len) {
    return;
  }

  node_t *current_node = get_node(heap->list, index);
  if (!current_node) {
    return;
  }

  if (key > current_node->value) {
    return;
  }

  current_node->value = key;
  while (index > 0) {
    size_t parent = (index - 1) / 2;
    node_t *parent_node = get_node(heap->list, parent);
    if (!parent_node) {
      return;
    }

    if (parent_node->value <= current_node->value) {
      break;
    }

    current_node = pop_node(heap->list, index);
    parent_node = pop_node(heap->list, parent);
    insert_node(heap->list, parent, current_node);
    insert_node(heap->list, index, parent_node);

    index = parent;
  }
}

/**
 * Merges two unsorted min heaps into a single heap.
 *
 * This function takes two unsorted min heaps, `heap_a` and `heap_b`, and merges
 * them into a single heap. The resulting heap will contain all the elements
 * from both `heap_a` and `heap_b`, and will be sorted in ascending order.
 *
 * @param heap_a Pointer to the first min heap.
 * @param heap_b Pointer to the second min heap.
 */
void union_unsorted_min_heaps(min_heap_t *heap_a, min_heap_t *heap_b) {
  if (!heap_a || !heap_a->list || !heap_b || !heap_b->list) {
    return;
  }

  if (heap_b->list->len == 0) {
    return;
  }

  if (heap_a->list->len == 0) {
    heap_a->list = heap_b->list;
    heap_b->list = NULL;
    return;
  }

  node_t *current_node = pop_first(heap_b->list);
  while (current_node) {
    add_last(heap_a->list, current_node);
    current_node = pop_first(heap_b->list);
  }

  build_min_heap(heap_a->list, false);
}

/**
 * Combines two sorted min heaps into a single sorted min heap.
 *
 * @param heap_a Pointer to the first min heap.
 * @param heap_b Pointer to the second min heap.
 */
void union_sorted_min_heaps(min_heap_t *heap_a, min_heap_t *heap_b) {
  if (!heap_a || !heap_a->list || !heap_b || !heap_b->list) {
    return;
  }

  if (heap_b->list->len == 0) {
    return;
  }

  if (heap_a->list->len == 0) {
    heap_a->list = heap_b->list;
    heap_b->list = NULL;
    return;
  }

  linked_list_t *new_list = create_list();
  if (!new_list) {
    return;
  }

  node_t *current_a = pop_first(heap_a->list);
  node_t *current_b = pop_first(heap_b->list);

  while (current_a || current_b) {
    node_t *smallest = NULL;

    if (current_a == NULL || current_b == NULL) {
      smallest = current_a ? current_a : current_b;
    } else {
      smallest = current_a->value < current_b->value ? current_a : current_b;
    }

    if (smallest == current_a) {
      current_a = pop_first(heap_a->list);
    } else {
      current_b = pop_first(heap_b->list);
    }

    add_last(new_list, smallest);
  }

  destroy_list(heap_a->list);
  heap_a->list = new_list;
}

min_heap_t build_min_heap(linked_list_t *list, bool is_sorted) {
  min_heap_t heap;
  heap.list = list;
  heap.is_sorted = is_sorted;

  if (!list || list->len == 0 || is_sorted) {
    return heap;
  }

  for (int i = (list->len / 2) - 1; i >= 0; i--) {
    min_heapify(&heap, i);
  }

  return heap;
}

node_t *min_heap_extract_min(min_heap_t *heap) {
  if (!heap || !heap->list) {
    return NULL;
  }

  node_t *min = pop_first(heap->list);
  if (!min) {
    return NULL;
  }

  if (heap->is_sorted) {
    return min;
  }

  node_t *last = pop_last(heap->list);
  if (!last) {
    return min;
  }
  add_first(heap->list, last);

  min_heapify(heap, 0);

  return min;
}

void min_heap_insert(min_heap_t *heap, int value) {
  if (!heap || !heap->list) {
    return;
  }

  if (heap->is_sorted) {
    node_t *current = get_node(heap->list, 0);
    size_t index = 0;
    if (!current) {
      add_first(heap->list, create_node(value));
      return;
    }

    while (current && current->value < value) {
      current = current->next;
      index++;
    }

    insert_node(heap->list, index, create_node(value));
    return;
  }

  node_t *new_node = create_node(INT_MAX);
  if (!new_node) {
    return;
  }

  add_last(heap->list, new_node);
  min_heap_decrease_key(heap, heap->list->len - 1, value);
}

void union_min_heaps(min_heap_t *heap_a, min_heap_t *heap_b) {
  if (!heap_a || !heap_a->list || !heap_b || !heap_b->list) {
    return;
  }

  return heap_a->is_sorted && heap_b->is_sorted
             ? union_sorted_min_heaps(heap_a, heap_b)
             : union_unsorted_min_heaps(heap_a, heap_b);
}

void min_heap_sort(linked_list_t **list, bool is_sorted) {
  if (!list || !*list || (*list)->len == 0 || is_sorted) {
    return;
  }

  linked_list_t *sorted = create_list();

  min_heap_t heap = build_min_heap(*list, false);
  while (heap.list->len > 0) {
    node_t *min = min_heap_extract_min(&heap);
    if (!min) {
      return;
    }

    add_last(sorted, min);
  }

  destroy_list(heap.list);
  *list = sorted;
}
