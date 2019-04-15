#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int top;      // an number start from 0 to count the items  , we use it as an index
  unsigned max; // the maximum number of the stack
  int *arr;     // a pointer to an array because we can know how many items in the array

} Stack;

Stack *createStack(unsigned capacity) /// a function create a stack and return it
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));        /// allocate place in heap for the entire struct
  stack->top = -1;                                      // the top pointer is set to -1 , because the first element in the array is 0,
  stack->max = capacity;                                // maximum number of the stack
  stack->arr = (int *)malloc(sizeof(int) * stack->max); /// we allocate place in the heap for the array
  return stack;
}

int isEmpty(Stack *stack)
{
  if (stack->top == -1)
  {
    return 1;
  }
  return 0;
}

int isFull(Stack *stack)
{
  if (stack->top == stack->max - 1)
  {
    return 1;
  }
  return 0;
}

void add(Stack *stack, int item)
{
  if (isFull(stack))
  {
    return;
  }
  stack->arr[++stack->top] = item;
}

int pop(Stack *stack)
{
  if (isEmpty(stack) != 1)
  {
    int p;
    p = stack->arr[stack->top];
    stack->top--;
    return p;
  }

  return -1;
}