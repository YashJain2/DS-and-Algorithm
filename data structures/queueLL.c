#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
  int data;
  struct node *next;
};

struct queue
{
  struct node *front;
  struct node *rear;
};

struct queue *createQueue()
{
  struct queue *q;
  struct node *temp;
  q=malloc(sizeof(struct queue));
  if(!q)
  return NULL;
  temp=malloc(sizeof(struct node));
  q->front=q->rear=NULL;
  return q;
}

int size(struct queue *q)
{
  struct node *temp=q->front;
  int count=0;
  if(q->front==NULL && q->rear==NULL)
  return 0;
  while(temp!=q->rear)
  {
    count++;
    temp=temp->next;
  }
  if(temp==q->rear)
  count++;
  return count;
}

int frontElement(struct queue *q)
{
  return q->front->data;
}

int rearElement(struct queue *q)
{
  return q->rear->data;
}

void isEmpty(struct queue *q)
{
  if(q->front==NULL && q->rear==NULL)
  printf ("Empty Queue\n");
  else
  printf ("Queue is not empty\n");
}

void enQueue(struct queue *q, int num)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=num;
  temp->next=NULL;
  if(q->rear==NULL)
  q->front=q->rear=NULL;
  else
  {
    q->rear->next=temp;
    q->rear=temp;
  }
}

void deQueue(struct queue *q)
{
  struct node *temp;
  if(q->front==NULL)
  printf ("Queue is empty\n");
  else
  {
    temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    q->rear=NULL;
    printf("Removed Element : %d\n", temp->data);
    free(temp);
  }
}

void printQueue(struct queue *q)
{
  struct node *temp=q->front;
  if(q->front==NULL && q->rear==NULL)
  printf ("Queue is empty\n");
  while(temp!=NULL)
  {
    printf ("%d", temp->data);
    temp=temp->next;
    if(temp!=NULL)
    printf("-->");
  }
}

void deleteQueue(struct queue *q)
{
  struct node *temp;
  while(q->front)
  {
    temp=q->front;
    printf ("Element being deleted : %d\n",temp->data);
    q->front=q->front->next;
    free(temp);
  }
  free(q);
}

int main ()
{
  struct queue *q;
  q=createQueue();
  enQueue(q,1);
  enQueue(q,3);
  enQueue(q,5);
  enQueue(q,7);
  enQueue(q,9);
  enQueue(q,11);

  printQueue(q);
  printf ("\n Size of Queue : %d\n", size(q));
  printf ("Front ELement : %d\n", frontElement(q));
  printf ("Rear Element : %d\n", rearElement(q));

  deQueue(q);
  deQueue(q);
  deQueue(q);
  deQueue(q);
  deQueue(q);

  enQueue(q,13);
  enQueue(q,15);
  printQueue(q);
  printf ("\n Size of Queue : %d\n", size(q));
  printf ("Front ELement : %d\n", frontElement(q));
  printf ("Rear Element : %d\n", rearElement(q));
  deleteQueue(q);
  return 0;
}
