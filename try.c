#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x;
  x = 5;
  //////////////// we store the address of x in the pointer p
  int *p;
  p = &x;
  ///////////////////// we parint the values of x and the  value of the pointer p
  printf("1 ===>%d \n", x);
  printf("2 ===>%p \n", p);
  printf("3 ===>%p \n", p + 1); ///// printing the next pointer ( we can not print the value of because we dont know)
  //////////////////////we can print the value of x from p by derefrencing
  printf("4 ===>%d \n", *p);
  printf("5 ====>%d \n", *(&x)); // derefrencing the address where x is stored to get the value of x

  return 0;
}