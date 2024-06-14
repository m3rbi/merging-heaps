#include "linked_list.h"
#include <stdlib.h>

linked_list_t *create_list() {
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  if (!list) {
    return NULL;
  }

  list->head = NULL;
  list->tail = NULL;
  list->len = 0;

  return list;
}

void destroy_list(linked_list_t *list) {
  if (!list) {
    return;
  }

  if (list->len > 0) {
    node_t *current = pop_first(list);
    while (current) {
      destroy_node(current);
      current = pop_first(list);
    }
  }

  free(list);
}

node_t *create_node(int value) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  if (!node) {
    return NULL;
  }

  node->value = value;
  node->prev = NULL;
  node->next = NULL;

  return node;
}

void destroy_node(node_t *node) {
  if (!node) {
    return;
  }

  free(node);
}

int add_last(linked_list_t *list, node_t *node) {
  if (!list || !node) {
    return -1;
  }

  if (!list->tail) {
    list->head = node;
    list->tail = node;
    list->len = 1;
    return 1;
  }

  node->prev = list->tail;
  list->tail->next = node;
  list->tail = node;
  list->len++;
  return 1;
}

node_t *pop_last(linked_list_t *list) {
  if (!list || !list->tail) {
    return NULL;
  }

  node_t *last = list->tail;
  list->tail = last->prev;
  if (list->tail) {
    list->tail->next = NULL;
  } else {
    list->head = NULL;
  }

  last->prev = NULL;
  list->len--;

  return last;
}

int add_first(linked_list_t *list, node_t *node) {
  if (!list || !node) {
    return -1;
  }

  if (!list->head) {
    list->head = node;
    list->tail = node;
    list->len = 1;
    return 1;
  }

  node->next = list->head;
  list->head->prev = node;
  list->head = node;
  list->len++;

  return 1;
}
node_t *pop_first(linked_list_t *list) {
  if (!list || !list->head) {
    return NULL;
  }

  node_t *first = list->head;
  list->head = first->next;
  if (list->head) {
    list->head->prev = NULL;
  } else {
    list->tail = NULL;
  }

  first->next = NULL;
  list->len--;

  return first;
}

node_t *get_node(linked_list_t *list, size_t index) {
  if (!list || index >= list->len) {
    return NULL;
  }

  node_t *current = list->head;
  for (size_t i = 0; i < index; i++) {
    current = current->next;
  }

  return current;
}

node_t *pop_node(linked_list_t *list, size_t index) {
  if (!list || index >= list->len) {
    return NULL;
  }

  node_t *current = list->head;
  for (size_t i = 0; i < index; i++) {
    current = current->next;
  }

  if (!current->prev) {
    list->head = current->next;
  } else {
    current->prev->next = current->next;
  }

  if (!current->next) {
    list->tail = current->prev;
  } else {
    current->next->prev = current->prev;
  }

  current->prev = NULL;
  current->next = NULL;
  list->len--;

  return current;
}

void insert_node(linked_list_t *list, size_t index, node_t *node) {
  if (!list || index > list->len || !node) {
    return;
  }

  if (index == 0) {
    add_first(list, node);
    return;
  }

  if (index == list->len) {
    add_last(list, node);
    return;
  }

  node_t *current = list->head;
  for (size_t i = 0; i < index; i++) {
    current = current->next;
  }

  node->prev = current->prev;
  current->prev->next = node;

  node->next = current;
  current->prev = node;

  list->len++;
}
