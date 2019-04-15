#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  char app[] = {'a', 'd', 'a', 'm', '\0'};
  printf("%s\n", app);
  /////////////////////////////////////////
  char *p;
  p = "adam";
  printf("%s\n", p);
  ////////////////////////////////////////////
  int l;
  l = strlen(p);
  printf(" l: %d\n", l);
  ////////////////////////////////////////

  return 0;
}