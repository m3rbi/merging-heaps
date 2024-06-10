#include "operation_controller.h"

#include "program_operation.h"
#include "../operations/reset_state.h"
#include "../operations/exit_program.h"
#include "../operations/print_list.h"
#include "../operations/input_list.h"
#include "../operations/build_min_heap.h"
#include "../operations/heap_sort.h"
#include "../operations/union_heaps.h"


operation_t g_operations_map[MAX_OPERATION_TYPE] = {
    [RESET_STATE] = {
        RESET_STATE_NAME, RESET_STATE_PROMPT, run_reset_state
    },
    [INPUT_LIST] = {
      INPUT_LIST_NAME, INPUT_LIST_PROMPT, run_input_list
    },
    [PRINT_LIST] = {
        PRINT_LIST_NAME, PRINT_LIST_PROMPT, run_print_list
    },
    [EXIT_PROGRAM] = {
        EXIT_PROGRAM_NAME, EXIT_PROGRAM_PROMPT, run_exit_program
    },
    [BUILD_MIN_HEAP] = {
        BUILD_MIN_HEAP_NAME, BUILD_MIN_HEAP_PROMPT, run_build_min_heap
    },
    [HEAP_SORT] = {
        HEAP_SORT_NAME, HEAP_SORT_PROMPT, run_heap_sort
    },
    [UNION_HEAPS] = {
        UNION_HEAPS_NAME, UNION_HEAPS_PROMPT, run_union_heaps
    },
};

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
