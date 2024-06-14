#ifndef RUNTIME_PROGRAM_STATE_H_
#define RUNTIME_PROGRAM_STATE_H_

#include "../data_structures/linked_list.h"

#include <stdbool.h>

#include "../consts/consts.h"

typedef struct program_state_t {
  linked_list_t *list_a;
  linked_list_t *list_b;
  char last_error_message[ERROR_MESSAGE_SIZE];
  bool is_sorted;
} program_state_t;

#endif // RUNTIME_PROGRAM_STATE_H_