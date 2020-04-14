//This is a whole program code singly linked list which includes different
//operations such as insertion, traversing, deletion and further reversing
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *link
;}*first;
//traversing through linked list and displaying its elements
void display(struct node *p)
{
while(p)
{
printf ("%d\t",p->data);
p=p->link;
}
}

void insertbegin(int x)
{
  struct node *t;
  t=(struct node*)malloc(sizeof(struct node));
  t->data=x;
  t->link=first;
  first=t;
}

void insertend(int y)
{
  struct node *t,*p;
  t=(struct node*)malloc(sizeof(struct node));
  p=first;
  while(p->link!=NULL)
  p=p->link;
  t->data=y;
  t->link=NULL;
  p->link=t;
}

void insertRandom(int z, int n)
{
  struct node *t,*p=first;
for(int i=0;i<n-1;i++)
p=p->link;
  t=(struct node*)malloc(sizeof(struct node));
  t->data=z;
  t->link=(p->link)->link;
  p->link=t;
}

void deletebegin(struct node *p)
{
  first=p->link;
  free(p);
}

void deleteend(struct node *p)
{
  struct node *temp=p;
  while(p->link)
  {
    temp=p;
  p=p->link;
  }
temp->link=NULL;
  free(p);
}

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

void reverse(struct node *p)
{
  struct node *prev=NULL;
  struct node *nextnode=NULL;
  while(p!=NULL)
  {
    nextnode=p->link;
    p->link=prev;
    prev=p;
    p=nextnode;
  }
  first= prev;
}

void RecursiveReverse(struct node*prev, struct node *p)
{
  if(p)
  {
    RecursiveReverse(p,p->link);
    p->link=prev;
  }
  else
  first=prev;
}

void search(int b)
{
  struct node *p;
  if(first==NULL)
  exit(1);
  p=first;
  for(int i=1;p!=NULL; i++)
  {
    if(p->data==b)
    {
    printf("The position of the given data is %d\n",i );
    break;
    }
    p=p->link;
  }
}

int main()
{
int A[5];
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
printf ("\n");
int a,x,y,z,n,m;
scanf("%d\n", &a);
search(a);
scanf("%d",&x);
insertbegin(x);
printf ("\n");
display(first);
pritf ("\n");
scanf("%d",&y);
insertend(y);
printf ("\n");
display(first);
printf ("\n");
printf ("Enter the no. which you want to display and its position : ");
scanf("%d %d",&z ,&n);
insertRandom(z,n);
printf ("\n");
display(first);
printf ("\n");
deletebegin(first);
display(first);
printf ("\n");
deleteend(first);
display(first);
printf ("\n");
printf ("Enter the position you want to delete: ");
scanf("%d",&m);
printf ("\n");
deleterandom(first,m);
display(first);
printf ("\n");
RecursiveReverse(NULL,first);
display(first);
printf("\n");
reverse(first);
display(first);
printf ("\n");
return 0;
}
