#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int numerator;
  int denominator;

} fraction;

void printing(fraction bill); // we declare a function prototype called printing accepting fraction as parameter

int main()
{
  fraction myFraction; /// we create new version of the struct called myFraction

  myFraction.numerator = 1;
  myFraction.denominator = 3;

  printing(myFraction); //// we pass the myFraction stucture as parameter to printing function
  return 0;
}

void printing(fraction hill)
{
  printf(" ===> fraction : %d/%d \n", hill.numerator, hill.denominator);
}