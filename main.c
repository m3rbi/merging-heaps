#include "runtime/program_state.h"
#include "runtime/runtime.h"

int main(int argc, char *argv[]) {
  program_state_t state;
  state.list_a = NULL;
  state.list_b = NULL;

  run_program(&state);
}
