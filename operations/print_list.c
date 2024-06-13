#include "print_list.h"

#include "../io/print_utils.h"

operation_errcode_t run_print_list(program_state_t *state, const char *args) {
  if (!state || !args) {
    return NULL_PTR_ERROR;
  }

  linked_list_t *list = NULL;

  switch (args[0]) {
  case ('a'):
  case ('A'):
    list = state->list_a;
    break;
  case ('b'):
  case ('B'):
    list = state->list_b;
    break;
  default:
    return WRONG_ARGS;
  }

  print_list(list);

  return OPERATION_SUCCESS;
}