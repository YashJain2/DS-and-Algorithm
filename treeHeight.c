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
    printf ("Not entered any data\n");
    return NULL;
  }
  printf("Enter the left child of the rooted data %d\t",newnode->data);
  newnode->left=create();
  printf("Enter the right child of the rooted data %d\t",newnode->data);
  newnode->right=create();
  return newnode;
}


int height(struct node *root)
{
  if(root==NULL)
  return 0;
  int leftHeight= height(root->left);
  int rightHeight=height(root->right);
  return 1 + max(leftHeight,rightHeight);
}

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d\n",t->data);
    printf("\nHeight : %d\n", height(root));
    return 0;
  }
