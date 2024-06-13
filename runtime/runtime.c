#include "runtime.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_size_t.h>

#include "../consts/consts.h"
#include "../io/input_utils.h"
#include "operation_controller.h"
#include "program_operation.h"
#include "program_state.h"

void print_all_operations() {
  printf("Select operation -\n");

  for (operation_type_t operation_type = 0; operation_type < MAX_OPERATION_TYPE;
       operation_type++) {
    printf("[%5u] - %s\n", operation_type, get_operation_name(operation_type));
  }
}

operation_errcode_t handle_chosen_operation(program_state_t *state,
                                            operation_type_t operation_type) {
  const char *prompt = get_operation_prompt(operation_type);
  if (!prompt) {
    return execute_operation(state, operation_type, NULL);
  }

  char args[ARGS_BUFFER_SIZE];
  if (get_input(prompt, args, sizeof(args)) != 0) {
    return INPUT_ERROR;
  }

  return execute_operation(state, operation_type, args);
}

void run_program(program_state_t *state) {
  char is_sorted_buffer[COMMAND_BUFFER_SIZE];
  memset(is_sorted_buffer, 0, sizeof(is_sorted_buffer));

  while (is_sorted_buffer[0] != 'y' && is_sorted_buffer[0] != 'n') {
    if (get_input("Are the lists provided sorted? [y/n]", is_sorted_buffer,
                  sizeof(is_sorted_buffer)) != 0) {
      printf("Enter y/n only!\n");
    }
  }
  state->is_sorted = is_sorted_buffer[0] == 'y';

  while (1) {
    printf("-----------------------------\n");
    print_all_operations();
    char command_str[COMMAND_BUFFER_SIZE];
    if (get_input("Command id: ", command_str, sizeof(command_str)) != 0) {
      printf("Could not read input!\n");
      continue;
    }

    int command_id = atoi(command_str);
    if ((command_id == 0 && command_str[0] != '0') || command_id < 0 ||
        command_id >= MAX_OPERATION_TYPE) {
      printf("Invalid command id!\n");
      continue;
    }

    memset(state->last_error_message, 0, sizeof(state->last_error_message));

    operation_errcode_t errcode = handle_chosen_operation(state, command_id);
    switch (errcode) {
    case (OPERATION_SUCCESS):
      break;
    case (PROGRAM_EXIT):
      printf("Exiting program...\n");
      return;
    default:
      printf("Error executing command %u, errcode: %d\n", command_id, errcode);
      if (state->last_error_message[0] != 0x00) {
        printf("%s\n", state->last_error_message);
      }
      break;
    }
  }
}