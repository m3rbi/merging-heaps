#ifndef OPERATIONS_UNION_HEAPS_H_
#define OPERATIONS_UNION_HEAPS_H_

#include <stddef.h>

#include "../runtime/program_operation.h"

#define UNION_HEAPS_NAME ("Union heaps")
#define UNION_HEAPS_PROMPT (NULL)

/**
 * Performs the union operation on two heaps.
 *
 * This function merges the two specified lists into a single minimum heap, stored in `list_a`.
 * The original list in `list_a` is destroyed, and a new list is created in its place.
 * The original list in `list_b` is destroyed.
 *
 * @param state A pointer to the program state.
 * @param args  The arguments passed to the function (not used in this case).
 * @return An operation_errcode_t value indicating the success or failure of the operation.
 */
operation_errcode_t run_union_heaps(program_state_t *state, const char *args);

#endif // OPERATIONS_EXIT_PROGRAM_H_