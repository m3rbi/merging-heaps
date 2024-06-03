#include "exit_program.h"
#include "reset_state.h"

operation_errcode_t run_exit_program(program_state_t *state, const char *args) {
    run_reset_state(state, NULL);

    return PROGRAM_EXIT;
}