#include "heap_sort.h"

#include "../io/print_utils.h"
#include "../data_structures/heap.h"
#include <stdio.h>

operation_errcode_t run_heap_sort(program_state_t *state, const char *args) {
    if (!state || !args) {
        return NULL_PTR_ERROR;
    }

    linked_list_t **list = NULL;

    switch (args[0]) {
        case ('a'):
        case ('A'):
            list = &state->list_a;
            break;
        case ('b'):
        case ('B'):
            list = &state->list_b;
            break;
        default:
            return WRONG_ARGS;
    }
    if (!list) {
        return NULL_PTR_ERROR;
    }

    min_heap_sort(list, state->is_sorted);
    printf("Sorted list %c\n", args[0]);

    return OPERATION_SUCCESS;
}