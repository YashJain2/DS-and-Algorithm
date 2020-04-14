#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

//declaration of the tree element right, left and data type
struct node
{
  int data;
  struct node *left;
  struct node *right;
}*Node;

//Creating a Stack using linked list
struct stack
{
  int top;
  int capacity;
  int *array;
};

struct stack *createStack(int capacity)
{
  struct stack *s=malloc(sizeof(struct stack));
  if(!s)
  return NULL;
  s->capacity=capacity;
  s->top=-1;
  s->array=malloc(s->capacity*sizeof(int));
  if(!s->array)
  return NULL;
  return s;
}

int isEmpty(struct stack *s)
{
  return (s->top==-1);
}

int size(struct stack *s)
{
  return (s->top+1);
}

int isFull(struct stack*s)
{
  return (s->top==s->capacity-1);
}

void push(struct stack *s,int data)
{
  if(isFull(s))
  printf("Stack Overflow\n");
  else
  s->array[++s->top]=data;
}

int pop(struct stack*s)
{
  if(isEmpty(s))
  {
    printf ("Stack is empty\n");
    return INT_MIN;
  }
  else
  return (s->array[s->top--]);
}

int peek(struct stack*s)
{
  if(isEmpty(s))
  {
    printf ("Stack is empty\n");
    return INT_MIN;
  }
  else
  return (s->array[s->top]);
}

void delete(struct stack*s)
{
  if(s)
  {
    if(s->array)
    free(s->array);
    free(s);
  }
}

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
    printf ("Not entered any data\n");
    return NULL;
  }
  printf("Enter the left child of the rooted data : %d\t",newnode->data);
  newnode->left=create();
  printf("Enter the right child of the rooted data : %d\t",newnode->data);
  newnode->right=create();
  return newnode;
}


//traversing in a tree using non-recursive iterations
void inOrder(struct node *root)
{
  struct stack *s=createStack();
  while(1)
  {
    while(root)
    {
      push(s,root);
      root=root->left;
    }
    if(isEmpty(s))
    break;
    root=pop(s);
    printf("%d",root->data);
    root=root->right;
  }
  delete(s);
}

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d\n",t->data);
    printf ("Inorder traversal\n");
    inOrder(t);
    return 0;
  }
