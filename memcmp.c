#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

  int p[] = {1, 2, 3, 4};
  int c[] = {1, 2, 3, 8};
  if (memcmp(c, p, sizeof(p)) == 0)
  {
    printf(" ===> p & c are equal\n");
  }
  else
  {
    printf(" p & c are not equal!!!!!\n");
  };

  printf("====> %d\n", memcmp(c, p, sizeof(p)));

  return 0;
}