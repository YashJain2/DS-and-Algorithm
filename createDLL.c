#include <stdio.h>
#include <stdlib.h>

//declaring DLL structure
struct doublyLinkedList
{
  int data;
  struct doublyLinkedList *next;
  struct doublyLinkedList *prev;
}*first;

//creating doubly linked list using dynamic pointer
void create(int n)
{
  struct doublyLinkedList *p=first;
  p=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  scanf("%d", &p->data);
  p->next=NULL;
  p->prev=NULL;
  first=p;
while(n--)
{
  struct doublyLinkedList *t;
  t=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  scanf("%d", &t->data);
  t->next=NULL;
  t->prev=p;
  p->next=t;
  p=t;
}
}

void display(struct doublyLinkedList *p)
{
while(p)
{
  printf("%d\t", p->data);
  p=p->next;
}
}

int main ()
{
  int x,y,z,n,m,a;
  printf("Enter the number of data user want to enter\n");
  scanf("%d", &n);
  create(n-1);
  display(first);
  return 0;
}
