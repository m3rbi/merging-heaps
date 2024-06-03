#include "operation_controller.h"
#include "program_operation.h"

operation_t g_operations_map[MAX_OPERATION_TYPE] = {};

const char *get_operation_name(operation_type_t operation_type) {
  if (operation_type < 0 || operation_type >= MAX_OPERATION_TYPE) {
    return NULL;
  }

  return g_operations_map[operation_type].operation_name;
}

const char *get_operation_prompt(operation_type_t operation_type) {
  if (operation_type < 0 || operation_type >= MAX_OPERATION_TYPE) {
    return NULL;
  }

  return g_operations_map[operation_type].operation_prompt;
}

operation_errcode_t execute_operation(program_state_t *state,
                                       operation_type_t operation_type,
                                       char *args) {
  if (operation_type < 0 || operation_type >= MAX_OPERATION_TYPE) {
    return INPUT_ERROR;
  }

  return g_operations_map[operation_type].operation_function(state, args);
}
