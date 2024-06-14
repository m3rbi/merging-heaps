#include "print_utils.h"

#include <stdio.h>

void print_node(node_t *node) {
  if (!node) {
    printf("Cannot print NULL node!\n");
    return;
  }

  printf("%16p\t[%16p|%16p]\t%d", node, node->prev, node->next, node->value);
}

void print_list(linked_list_t *list) {
  if (!list) {
    printf("Cannot print NULL list!\n");
    return;
  }

  printf("List: %16p\nList size: %lu\n", list, list->len);
  node_t *current = list->head;
  while (current) {
    print_node(current);
    printf("\n");
    current = current->next;
  }
}