#include <stdio.h>
#include <stdlib.h>

void hello(void)
{
  printf("===> hello word !!! \n");
}

int *add(int *a, int *b)
{
  int *total;                  /// we declair a pointer
  total = malloc(sizeof(int)); /// the pointer recieve the pointer that malloc return inside the heap
  *total = *a + *b;            /// here is the trick , we give that pointer the value by using the dereferencing
  return total;                /// we return the address of that pointer thus will be dereferenced later in any function
}

int main()
{
  int x = 7;
  int y = 7;
  int *sum = add(&x, &y);
  hello();
  printf("the sum is : %d \n", *sum);
  return 0;
}
