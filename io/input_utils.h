#ifndef IO_INPUT_UTILS_H_
#define IO_INPUT_UTILS_H_

#include <stddef.h>

/**
 * Reads user input from the console and stores it in the provided character array.
 *
 * @param prompt The prompt message to display to the user.
 * @param result The character array to store the user input.
 * @param result_size The size of the character array.
 * @return Non-negative value on success, -1 on failure.
 */
int get_input(const char *prompt, char *result, const size_t result_size);

#endif // IO_INPUT_UTILS_H_
