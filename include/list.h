#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

Node node_create();
void node_delete(Node);

void clean_list(Node parent);
Node init_node_list(size_t);

char *get_nth_node_data(Node head, int index);
Node get_nth_node(Node, int);
void set_node_data(Node node, char *data);

void clean_list(Node parent) {
  if (!parent)
    return;

  Node previous = parent;
  Node current_node = parent->next;
  node_delete(previous);
  clean_list(current_node);
}

void set_node_data(Node node, char *data) {
  int data_length = strlen(data);
  node->data = (char *)malloc(data_length + 1 * sizeof(char));
  strcpy(node->data, data);
}

Node node_create() { return (Node)malloc(sizeof(Node)); }

void node_delete(Node node) {

  if (node->data != NULL) {
    free(node->data);
  }

  free(node);
}

Node get_nth_node(Node head, int index) {
  int count = index;

  if (count == 0) {
	  printf("They equal");
    return head;
  }
	
  while (head) {
    count++;
    head = head->next;
	  break;
  }

  return get_nth_node(head, count);
}

char *get_nth_node_data(Node head, int index) {
  return get_nth_node(head, index)->data;
}

Node init_node_list(size_t size) {

  Node parent = NULL;
  Node current_node = NULL;

  for (int i = 0; i < size; i++) {

    if (!parent) {
      parent = node_create();
      current_node = parent;
    } else {
      current_node->next = node_create();
      current_node = current_node->next;
      parent->prev = current_node;
    }
  }

  return parent;
}