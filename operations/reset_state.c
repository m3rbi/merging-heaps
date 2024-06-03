#include "reset_state.h"

operation_errcode_t run_reset_state(program_state_t *state, const char *args) {
    if (!state) {
        return NULL_PTR_ERROR;
    }

    destroy_list(state->list_a);
    state->list_a = NULL;
    
    destroy_list(state->list_b);
    state->list_b = NULL;

    return OPERATION_SUCCESS;
}