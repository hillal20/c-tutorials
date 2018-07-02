#include <stdio.h>
#include <stdlib.h>

int main()
{
  int b[2][3] = {1, 2, 3, 4, 5, 6};
  int(*p)[3];
  p = b;
  printf("1 ===>%p \n", b);
  printf("2 ===>%p \n", &b);
  printf("3 ===>%p \n", &b[0]);
  printf("4 ===>%p \n", *b);
  printf("5 ===>%p \n", &b[0][0]);
  printf("6 ===>%d \n", b[0][0]);
  printf("7 ===>%d \n", *(&b[0][0]));
  printf("8 ===>%d \n", **(&b[0]));
  return 0;
}