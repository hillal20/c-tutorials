#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
  int total;
  total = a + b;
  return total;
}

int main()
{

  int sum;
  sum = add(5, 6);
  printf("===> the sum is :%d \n", sum);
  //////////////////////////////////////////calling the function add via function-pointer
  int (*p)(int, int);
  p = &add;
  //p = add;  the same thing as arrays , add is the address of the first instruction of the function , add is naturally a pointer
  int c;
  c = (*p)(5, 6);
  //c = p(5, 6); since p is pointer to a function, we can use it as the name of that function GREAT!!!!!
  printf("====> the sum via pointer: %d \n", c);
  return 0;
}