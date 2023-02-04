#pragma once

#define error(message) printf("[ERROR] \033[31;31m %s \033[m", message)

struct Node {
  struct Node *next;
  struct Node *prev;
  char *data;
};

typedef struct Node *Node;

typedef struct Node Node_;
