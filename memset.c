#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // int p[] = {1, 2, 3, 4, 5};
  int *newp;
  newp = malloc(sizeof(int) * 5);
  ///////////////////////////////////////////////////////////////////////

  memset(newp, 0, sizeof(int) * 5);
  printf("====> %d\n", newp[0]);

  /////////////////////////////////////////////////////////////////////////

  char *bill;
  bill = malloc(sizeof(char) * 5);

  /////////////////////////////////////////////////////////////////////////////////////

  memset(bill, 'B', sizeof(char) * 5);
  printf("===> %c\n", bill[3]);

    return 0;
}