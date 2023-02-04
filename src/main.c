#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_SIZE 10

int main() {
  Node parent = init_node_list(LIST_SIZE);

  Node current = parent;
  int count = 0;

  while (current) {
    char data[15];
    sprintf(data, "%d", count);
    set_node_data(current, data);
    current = current->next;
    count++;
  }

 if(!parent){
	 printf("parent is null\n");
 }else{
	 printf("parent is fine\n");
 }

  Node n = get_nth_node(parent, 1);

  if (!n) {
    error("node outside range\n");
    return 1;
  }

  printf("DATA at 0 - %s\n", parent->data);
  if (parent->prev) {
    printf("LAST ITEM %s\n", parent->prev->data);
  }

  clean_list(parent);

  return 0;
}