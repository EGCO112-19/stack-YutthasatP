
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node){
    new_node->data=value;
    new_node->nextPtr = s->top;
    s->top = new_node;
  }
  s->size ++;
}
char pop(StackPtr s)
{
  NodePtr t = s->top;
  char c;
  t = s->top;
  c = t->data;
  s->top = t->nextPtr;
  free (t);
  s->size--;
  return c;
}
void pop_all(StackPtr s)
{
  int i;
  NodePtr t = s->top;
  char c;
  while (s->size != 0)
  {
    t = s->top;
    c = t->data;
    s->top = t->nextPtr;
    free (t);
    printf ("popping %c\n",c);
    s->size--;
  }
}
#endif
