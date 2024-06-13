#ifndef DATA_STRUCTURES_FILE_LIST_PARSER_H_
#define DATA_STRUCTURES_FILE_LIST_PARSER_H_

#include "linked_list.h"

typedef enum {
  FILE_LIST_PARSER_OK,
  FILE_NOT_FOUND,
  MEMORY_ERROR,
  FILE_OPEN_ERROR,
  FILE_READ_ERROR,
  FILE_EMPTY,
  FILE_INVALID_NODES
} file_list_parser_error_t;

/**
 * Parses a list from a file.
 *
 * This function reads the contents of the specified file and parses it into a
 * linked list.
 *
 * @param filename The name of the file to parse.
 * @param list A pointer to a linked list where the parsed data will be stored.
 * @return A file_list_parser_error_t value indicating the success or failure of
 * the parsing operation.
 */
file_list_parser_error_t parse_list_from_file(const char *filename,
                                              linked_list_t **list);

#endif // DATA_STRUCTURES_FILE_LIST_PARSER_H_
