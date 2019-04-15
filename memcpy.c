#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int array[] = {1, 2, 3, 4}; /// array is a local variable in the stack
  int *newArray;

  newArray = malloc(sizeof(int) * 4);           /// we allocate space for 4 integers in the heap
  memcpy(&newArray[0], array, sizeof(int) * 4); /// we copy the content of the array to newarray
  //memcpy(newArray, array, sizeof(int) * 4); the same thing because the name of array is naturally a pointer
  for (int i = 0; i < 4; i++)
  {
    printf("==>%d\n", newArray[i]);
  }
  free(newArray); // free memory
  ///////////////////////////////////////
  char arr[] = "hilal like pizza";
  char *newarr;

  newarr = "bilal";

  memcpy(&arr[0], newarr, sizeof(char) * 5);
  printf("====> %s\n", arr);

  return 0;
}