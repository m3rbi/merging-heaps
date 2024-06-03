#ifndef RUNTIME_RUNTIME_H_
#define RUNTIME_RUNTIME_H_

#include "program_state.h"

/**
 * Runs the program using the provided program state.
 *
 * This program is the main user interface for the program, it will prompt the
 * user for input and execute the appropriate operation.
 *
 * @param state A pointer to the program state.
 */
void run_program(program_state_t *state);

#endif