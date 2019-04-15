#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  FILE *filepointer;
  filepointer = fopen("file.txt", "r");

  char buffer[1025]; /// empty array to store
  char *memo;        //// empty pointer

  char *p; //// empty pointer

  while (!feof(filepointer)) /// since we are not the the end of file , keep reading
  {
    fgets(buffer, 1025, filepointer);
    //puts(buffer);
    // printf("%s \n", buffer);
    memo = malloc(sizeof(char) * 1025);
    memcpy(memo, &buffer[0], 1025);
    // //memset(memo, 0, sizeof(char) * 1025);
    // free(memo);

    p = strchr(buffer, '\n'); /// look new line
    *p = '\0';

    printf("%s \n", memo);
  }

  // char c;
  // do
  // {
  //   c = fgetc(filepointer);
  //   printf("===> : %c \n", c);

  // } while (c != EOF);

  fclose(filepointer);
  return 0;
}