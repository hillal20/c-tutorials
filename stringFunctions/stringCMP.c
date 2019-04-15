#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *bill = "hello";
  char *fill = "hall";
  int l;
  l = strcmp(bill, fill);
  //l = strcmp(&bill[0], &fill[0]); the same thing
  printf(" strcmp: %d\n", l);
  ///////////////////////////////////////////

  int c;
  c = strncmp(bill, fill, 3);
  printf(" strncmp: %d\n", l);
  return 0;
}