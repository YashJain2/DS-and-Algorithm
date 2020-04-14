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


void deleteRandom(int a)
{
  struct doublyLinkedList *p,*temp=first;
  p=first;
  for(int i=1;i<a;i++)
  {
    temp=p;
    p=p->next;
  }
  temp->next = p->next;
  p->next->prev=temp;
  free(p);
}

int main ()
{
  int x,n;
  printf("Enter the number of data user want to enter and the position of integer to be deleted\n");
  scanf("%d %d", &n ,&x);
  create(n-1);
  pritnf ("\n The initial linked list is : ");
  display(first);
  deleteRandom(x);
  printf("\nThe final entry after deletion : ");
  display(first);
  return 0;
}
