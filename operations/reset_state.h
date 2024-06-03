#ifndef OPERATIONS_RESET_STATE_H_
#define OPERATIONS_RESET_STATE_H_

#include <stddef.h>

#include "../runtime/program_operation.h"

#define RESET_STATE_NAME ("Reset State")
#define RESET_STATE_PROMPT (NULL)

/**
 * Resets the state of the program.
 *
 * This function resets the state of the program by clearing all the data and
 * setting the program state to its initial values.
 *
 * @param state A pointer to the program state structure.
 * @param args  The arguments passed to the function (not used in this case).
 * @return An operation error code indicating the success or failure of the operation.
 */
operation_errcode_t run_reset_state(program_state_t *state, const char *args);

#endif // OPERATIONS_RESET_STATE_H_
