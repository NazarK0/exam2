#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  Node *next;
} Node;

struct Ware
{
  int id;
  char *title;
  char *date;
};

void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

main()
{

  return 0;
}