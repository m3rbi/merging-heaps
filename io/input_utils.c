#include "input_utils.h"

#include <stdio.h>
#include <string.h>

int get_input(const char *prompt, char *result, const size_t result_size) {
  if (prompt) {
    printf("%s", prompt);
  }

  memset(result, 0, result_size);

  if (fgets(result, result_size, stdin) <= 0) {
    return -1;
  }

  strtok(result, "\n");

  return 0;
}
