#ifndef OPERATIONS_INPUT_LIST_H_
#define OPERATIONS_INPUT_LIST_H_

#include "../runtime/program_operation.h"

#define INPUT_LIST_NAME ("Input List")
#define INPUT_LIST_PROMPT ("Enter <list name> <file_path>:")

/**
 * Runs the input list operation.
 *
 * This operation reads the contents of a file and parses it into a linked list, which is then stored in the program state.
 *
 * @param state A pointer to the program state.
 * @param args Expects two arguments: the list name and the file path.
 * @return An operation_errcode_t value indicating the success or failure of the operation.
 */
operation_errcode_t run_input_list(program_state_t *state, const char *args);

#endif // OPERATIONS_INPUT_LIST_H_
