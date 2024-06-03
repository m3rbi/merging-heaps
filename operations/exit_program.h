#ifndef OPERATIONS_EXIT_PROGRAM_H_
#define OPERATIONS_EXIT_PROGRAM_H_

#include <stddef.h>

#include "../runtime/program_operation.h"

#define EXIT_PROGRAM_NAME ("Exit Program")
#define EXIT_PROGRAM_PROMPT (NULL)

/**
 * Runs the exit program operation.
 *
 * This function is responsible for executing the exit program operation.
 * It terminates the program and frees any allocated resources.
 *
 * @param state A pointer to the program state.
 * @param args The arguments passed to the operation (not used in this case).
 * @return The error code indicating the success or failure of the operation.
 */
operation_errcode_t run_exit_program(program_state_t *state, const char *args);

#endif // OPERATIONS_EXIT_PROGRAM_H_