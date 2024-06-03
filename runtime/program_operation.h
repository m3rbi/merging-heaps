#ifndef RUNTIME_PROGRAM_OPERATION_H_
#define RUNTIME_PROGRAM_OPERATION_H_

#include "program_state.h"

typedef enum {
  RESET_STATE,
  INPUT_LIST,
  PRINT_LIST,
  EXIT_PROGRAM,
  MAX_OPERATION_TYPE,
} operation_type_t;

typedef enum {
  OPERATION_SUCCESS,
  INPUT_ERROR,
  WRONG_ARGS,
  PROGRAM_EXIT,
  NULL_PTR_ERROR,
  LIST_PARSING_ERROR,
} operation_errcode_t;

typedef operation_errcode_t (*operation_function_t)(
    program_state_t *program_state, const char *operation_args);

typedef struct operation_t {
  const char *operation_name;
  const char *operation_prompt;
  operation_function_t operation_function;
} operation_t;

#endif // RUNTIME_PROGRAM_OPERATION_H_