#include "insert_node.h"

#include <stdlib.h>
#include <string.h>

#include "../data_structures/heap.h"

operation_errcode_t run_insert_node(program_state_t *state, const char *args) {
    if (!state || !args) {
        return NULL_PTR_ERROR;
    }

    char args_copy[ARGS_BUFFER_SIZE];
    memset(args_copy, 0, ARGS_BUFFER_SIZE);
    memcpy(args_copy, args, ARGS_BUFFER_SIZE);
    char *list_type = strtok(args_copy, " ");
    if (!list_type) {
        return WRONG_ARGS;
    }

    linked_list_t *list = NULL;
    switch (list_type[0]) {
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
        return UNINITIALIZED_LIST;
    }
    
    char *node_value = strtok(NULL, " ");
    if (!node_value) {
        return WRONG_ARGS;
    }
    int value = atoi(node_value);
    if (node_value[0] == '0' && value == 0) {
        return WRONG_ARGS;
    }

    min_heap_t heap = build_min_heap(list, state->is_sorted);
    min_heap_insert(&heap, value);

    return OPERATION_SUCCESS;
}