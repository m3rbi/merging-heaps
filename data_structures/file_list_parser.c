#include "file_list_parser.h"

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

file_list_parser_error_t parse_list_from_file(const char *filename,
                                              linked_list_t **list) {
  struct stat st;
  if (stat(filename, &st) != 0) {
    return FILE_NOT_FOUND;
  }

  if (st.st_size <= 0) {
    return FILE_EMPTY;
  }

  int fd = open(filename, O_RDONLY);
  if (fd < 0) {
    return FILE_OPEN_ERROR;
  }

  char *buffer = (char *)malloc(sizeof(char) * st.st_size);
  if (!buffer) {
    close(fd);
    return FILE_READ_ERROR;
  }

  int read_bytes = read(fd, buffer, st.st_size);

  close(fd);
  if (read_bytes != st.st_size) {
    free(buffer);
    return FILE_READ_ERROR;
  }

  *list = create_list();
  if (!*list) {
    free(buffer);
    return MEMORY_ERROR;
  }

  for (char *current_node = strtok(buffer, "\n"); current_node;
       current_node = strtok(NULL, "\n")) {
    int value = atoi(current_node);
    if (value == 0 && current_node[0] != '0') {
      destroy_list(*list);
      free(buffer);
      return FILE_INVALID_NODES;
    }

    node_t *node = create_node(value);
    if (!node) {
      destroy_list(*list);
      free(buffer);
      return MEMORY_ERROR;
    }

    add_last(*list, node);
  }

  free(buffer);
  return FILE_LIST_PARSER_OK;
}
