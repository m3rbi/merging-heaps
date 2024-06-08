#ifndef OPERATIONS_BUILD_MIN_HEAP_H_
#define OPERATIONS_BUILD_MIN_HEAP_H_

#include "../runtime/program_operation.h"

#define BUILD_MIN_HEAP_NAME ("Build min heap from list")
#define BUILD_MIN_HEAP_PROMPT ("Enter list name (a/b):")

/**
 * Modifies one of the program's lists to be a minimum heap.
 *
 * @param state A pointer to the program state.
 * @param args  Expects a single character argument indicating the list to build the heap from.
 * @return      An operation error code indicating the success or failure of the operation.
 */
operation_errcode_t run_build_min_heap(program_state_t *state, const char *args);

#endif // OPERATIONS_BUILD_MIN_HEAP_H_
