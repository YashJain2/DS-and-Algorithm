#include <stdio.h>
#include <srdlib.h>
#include <limits.h>

struct Queue
{
  int front, rear;
  int capacity;
  int size;
  int *array;
};

struct Queue *createQueue(int capacity)
{
  struct Queue *Q=malloc(sizeof(struct Queue));
  if(!Q)
  return NULL;
  Q->capacity=capacity;
  Q->front=Q->rear=-1;
  Q->size=0;
  Q->array=malloc(Q->capacity*sizeof(int));
  if(!Q->array)
  return NULL;
  return Q;
}

int size (struct Queue *Q)
{
  return Q->size;
}

int frontElement(struct Queue *Q)
{
  return Q->array[Q->front];
}

int rearElement(struct Queue *Q)
{
  return Q->array[Q->rear];
}

int isEmpty(struct Queue *Q)
{
  return Q->size==0;
}

int isFull(struct Queue *Q)
{
  return (Q->size==Q->capacity);
}

void enQueue(struct Queue *Q, int data)
{
  if(isFull(Q))
  printf ("Queue overflow\n");
  else
  {
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->array[Q->rear]=data
    if(Q->front==-1)
    Q->front=Q->rear;
    Q->size+=1;
  }
}

int deQueue(struct Queue *Q)
{
  int data=INT_MIN;
  if(isEmpty(Q))
  {
    printf ("Queue is Empty\n");
    return data;
  }
  data=Q->array[Q->front];
  if(Q->front==Q->rear)
  {
    Q->front=Q->rear=-1;
    Q->size=0;
  }
  else
  {
    Q->front=(Q->front+1)%Q->capacity;
    Q->size-=1;
  }
  return data;
}

void deleteQueue(struct Queue *Q)
{
  if(Q)
  {
    if(Q->array)
    free(Q->array);
    free(Q);
  }
}

int main ()
{
  struct Queue *Q;
  Q=createQueue(4);
  enQueue(Q,1);
  enQueue(Q,3);
  enQueue(Q,5);
  enQueue(Q,7);
  enQueue(Q,9);
  printf ("\n Size of Queue : %d\n", size(Q));
  printf ("Front element : %d", frontElement(Q));
  printf ("Rear element : %d", rearElement(Q));

  printf ("\nDequeue element : %d\n", deQueue(Q));
  printf ("\nDequeue element : %d\n", deQueue(Q));
  printf ("\nDequeue element : %d\n", deQueue(Q));
  printf ("\nDequeue element : %d\n", deQueue(Q));
  printf ("\nDequeue element : %d\n", deQueue(Q));
  enQueue (Q,15);
  enQueue(Q,100);

  printf ("\n Size of queue : %d\n", size(Q));
  printf ("Front element : %d", frontElement(Q));
  printf ("Rear element : %d", rearElement(Q));
  deleteQueue(Q);
  return 0;
}
