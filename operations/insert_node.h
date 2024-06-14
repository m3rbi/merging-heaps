#ifndef OPERATIONS_INSERT_NODE_H_
#define OPERATIONS_INSERT_NODE_H_

#include "../runtime/program_operation.h"

#define INSERT_NODE_NAME ("Insert Node")
#define INSERT_NODE_PROMPT ("Enter <list name> <node value>:")

/**
 * Inserts a node into the heap.
 *
 * This function inserts a node into the specified heap maintaining the heap
 * property.
 *
 * @param state The program state containing the heap.
 * @param args Expects two arguments: the list name and the file path.
 * @return An operation_errcode_t value indicating the success or failure of the
 * operation.
 */
operation_errcode_t run_insert_node(program_state_t *state, const char *args);

#endif // OPERATIONS_INSERT_NODE_H_
