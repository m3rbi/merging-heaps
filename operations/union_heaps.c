#include "union_heaps.h"

#include <stdio.h>

#include "../data_structures/heap.h"

operation_errcode_t run_union_heaps(program_state_t *state, const char *args) {
    if (!state) {
        return NULL_PTR_ERROR;
    }

    if (!state->list_a || !state->list_b) {
        return UNINITIALIZED_LIST;
    }

    min_heap_t heap_a = build_min_heap(state->list_a, state->is_sorted);
    min_heap_t heap_b = build_min_heap(state->list_b, state->is_sorted);

    union_min_heaps(&heap_a, &heap_b);
    state->list_a = heap_a.list;
    state->list_b = heap_b.list;

    destroy_list(state->list_b);
    state->list_b = NULL;

    return OPERATION_SUCCESS;
}