#include <stdio.h>
#include<limits.h>
#include<stdlib.h>
#include <ctype.h>
//declaration of the tree element right, left and data type
struct node
{
  int data;
  struct node *left;
  struct node *right;
}*Node;

int max(int a, int b)
{
  return (a>b)?a:b;
}

/*
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
*/
struct node *create()
{
  int x;
  //struct node *newnode;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  printf ("Enter the data for the nodes (-1 for no data)");
  scanf("%d",&x);
  newnode->data=x;
  if(x==-1)
  {
    printf ("No data\n");
    return NULL;
  }
  printf("Enter the left child of the rooted data %d\t",newnode->data);
  newnode->left=create();
  printf("Enter the right child of the rooted data %d\t",newnode->data);
  newnode->right=create();
  return newnode;
}

int leafNumber(struct node *root)
{
  int count =0;
  if(root->right==NULL && root->left==NULL)
  return count+=1;
  int x=leafNumber(root->left);
  int y=leafNumber(root->right);
  return x+y;
}

/*
int leafNonRecursive(struct node *root)
{
  if(!root)
  return 0;
  struct node *temp;
  struct queue *q=createQueue();
  enQueue(q,root);
  while(!isEmpty(q))
  {
    temp=deQueue(q);
    if(!temp->left && !temp->right)
    count++;
    else
    {
      if(temp->left)
      enQueue(q,temp->left);
      if(temp->right)
      enQueue(q,temp->right);
    }
  }
  deleteQueue(q);
  return count;
}
*/

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d\n",t->data);
    printf ("Number of leaf nodes : %d", leafNumber(root));
    return 0;
  }
