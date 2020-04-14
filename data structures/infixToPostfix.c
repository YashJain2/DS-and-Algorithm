#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<limits.h>
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
  s->array=malloc(s->capacity*sizeof(char));
  if(!s->array)
  return NULL;
  return s;
}

int isEmpty(struct stack *s)
{
  return (s->top==-1);
}

int isFull(struct stack*s)
{
  return (s->top==s->capacity-1);
}

void push(struct stack *s,char data)
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
    return INT_MIN;
  }
  else
  return (s->array[s->top]);
}

int priority(char x)
{
  if(x=='(')
  return 0;
  if(x=='+' || x=='-')
  return 1;
  if(x=='*' || x=='/')
  return 2;
}

int infixToPostfix(char expression[])
{
  char *e,x;
  struct stack *s=createStack(8);
  e=expression;
  while(*e!='\0')
  {
    if(isalnum(*e))
    printf("%c",*e);
    else if(*e=='(')
    push(s,*e);
    else if(*e==')')
    {
      while((x=pop(s))!='(')
      printf("%c",x);
    }
    else
    {
      while(priority(peek(s))>=priority(*e))
      printf("%c",pop(s));
      push(s,*e);
    }
    e++;
  }
    while(!isEmpty(s))
    printf("%c", pop(s));
}


int main ()
{
  infixToPostfix("a*b-(c+d)+e");
  return 0;
}
