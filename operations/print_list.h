#ifndef OPERATIONS_PRINT_LIST_H_
#define OPERATIONS_PRINT_LIST_H_

#include "../runtime/program_operation.h"

#define PRINT_LIST_NAME ("Print List")
#define PRINT_LIST_PROMPT ("Enter list name (a/b):")

/**
 * @brief Prints the elements of a list.
 *
 * This function prints the elements of specified list in the program state.
 *
 * @param state A pointer to the program state.
 * @param args Expects a single character argument indicating the list to print.
 * @return An operation_errcode_t value indicating the success or failure of the
 * operation.
 */
operation_errcode_t run_print_list(program_state_t *state, const char *args);

#endif // OPERATIONS_PRINT_LIST_H_
