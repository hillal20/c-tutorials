#include <stdio.h>
#include <stdlib.h>

void Hello(void) /////// hello is cb;
{

  printf("===> hello friends!!! \n");
}

void Bill(void (*x)()) //// passing the function pointer of Hello to Bill
{
  (*x)();
}

int main()
{

  void (*p)();
  p = &Hello; ///  giving the address of the function Hello to the function pointer p
  Bill(p);    //// passing the pointer of the function Hello into the function Bill
  return 0;
}