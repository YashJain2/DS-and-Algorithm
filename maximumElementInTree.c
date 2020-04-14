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

int Max(struct node *root)
{
  int value,left,right,max=INT_MIN;
  if(root!=NULL)
  {
    value=root->data;
    left=Max(root->left);
    right=Max(root->right);
    if(left>right)
    max=left;
    else
    max=right;
    if(value>max)
    max=value;
  }
  return max;
}

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d\n",t->data);
    printf (" Maximum element of the Tree : %d", Max(root));
    return 0;
  }
