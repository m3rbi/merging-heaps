#ifndef RUNTIME_OPERATION_CONTROLLER_H_
#define RUNTIME_OPERATION_CONTROLLER_H_

#include "program_operation.h"
#include "program_state.h"

/**
 * Retrieves the name of the operation based on the given operation type.
 *
 * @param operation_type The type of the operation.
 * @return The name of the operation as a null-terminated string.
 */
const char *get_operation_name(operation_type_t operation_type);

/**
 * Retrieves the prompt for the operation based on the given operation type.
 *
 * @param operation_type The type of the operation.
 * @return The prompt for the operation as a null-terminated string.
 */
const char *get_operation_prompt(operation_type_t operation_type);

/**
 * Executes the operation specified by the operation type with the given arguments.
 *
 * @param state A pointer to the program state.
 * @param operation_type The type of the operation to execute.
 * @param args The arguments to pass to the operation.
 * @return An operation error code indicating the success or failure of the operation.
 */
operation_errcode_t execute_operation(program_state_t *state,
                                       operation_type_t operation_type,
                                       char *args);

#endif // RUNTIME_OPERATION_CONTROLLER_H_