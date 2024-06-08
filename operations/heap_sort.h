#ifndef OPERATIONS_HEAP_SORT_H_
#define OPERATIONS_HEAP_SORT_H_

#include "../runtime/program_operation.h"

#define HEAP_SORT_NAME ("Heap Sort")
#define HEAP_SORT_PROMPT ("Enter list name (a/b):")

/**
 * Sorts the heap in ascending order using the heap sort algorithm.
 *
 * @param state A pointer to the program state.
 * @param args Expected to be a single character indicating the list to sort.
 * @return An operation error code indicating the success or failure of the operation.
 */
operation_errcode_t run_heap_sort(program_state_t *state, const char *args);

#endif // OPERATIONS_HEAP_SORT_H_
