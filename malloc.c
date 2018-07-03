#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  scanf("%d", &n);
  printf(" ===> the number is entered  : %d \n", n);

  //int a[n]; we can not do that because the size of the n is not know for memory
  //int a[9]; we can not because the number of elemnet is 9 and in case we enter n bigger than 9 , example n=10

  int *a;
  a = (int *)malloc(n * sizeof(int)); // malloc return a void  pointer , we cast it based on the pointer type assigned to it
  //a = (int*)calloc(n, sizeof(int)); malloc & calloc allocate the right  memory;

  for (int i = 0; i < n; i++)
  {
    a[i] += i;
    printf("number:%d \n", a[i]);
  }
  free(a); // free the memory from allocation
  return 0;
}