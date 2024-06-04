#include "input_list.h"

#include <stdio.h>
#include <string.h>

#include "../data_structures/file_list_parser.h"
#include "../data_structures/heap.h"
#include "../consts/consts.h"

operation_errcode_t run_input_list(program_state_t *state, const char *args) {
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

    linked_list_t **list = NULL;
    switch (list_type[0]) {
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
    destroy_list(*list);
    char *file_path = strtok(NULL, " ");
    if (!file_path) {
        return WRONG_ARGS;
    }

    file_list_parser_error_t errcode = parse_list_from_file(file_path, list);
    if (errcode != FILE_LIST_PARSER_OK) {
        sprintf(state->last_error_message, "Parsing failed with code: %d", errcode);
        return LIST_PARSING_ERROR;
    }

    return OPERATION_SUCCESS;
}