#include "build_min_heap.h"

#include "../data_structures/heap.h"
#include <stdio.h>

operation_errcode_t run_build_min_heap(program_state_t *state,
                                       const char *args) {
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
  if (!list) {
    return NULL_PTR_ERROR;
  }

  build_min_heap(list, state->is_sorted);
  printf("List %c is now a minimum heap\n", args[0]);

  return OPERATION_SUCCESS;
}