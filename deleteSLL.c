#include <stdio.h>
#include <stdlib.h>

//Declaring a  singly list node structure
struct node
{
int data;
struct node *link;
}*first;

//traversing through linked list and displaying its elements
void display(struct node *p)
{
while(p)
{
printf ("%d\t",p->data);
p=p->link;
}
}

//deleting random integer
void deleterandom(struct node *p,int m)
{
  struct node *temp;
  int x=m-1;
while(x--)
{
 temp=p;
 p=p->link;
}
temp->link=p->link;
free(p);
}

//creating SLL using array
int main()
{
int A[5],x;
struct node *p,*t;
p=(struct node*)malloc(sizeof(struct node));
scanf("%d", &A[0]);
p->data=A[0];
p->link=NULL;
first=p;
for(int i=1;i<5;i++)
{
t=(struct node*)malloc(sizeof(struct node));
scanf("%d", &A[i]);
t->data=A[i];
t->link=NULL;
p->link=t;
p=t;
}
display(first);
printf("/nEnter the integer position to be discarded :");
scanf(" %d/n", &x);
deleterandom(first,x);
return 0;
}
