#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a[] = {1, 2, 3, 4, 5}; /// in c the name of the array is naturally considered as a pointer to the fist element in array
  int *p;
  p = a;
  ////////////////////////   a = &a = p = &a[0] ===>  greate and very important
  printf("1 ===>%p \n", p);
  printf("2 ===>%p \n", a);
  printf("3 ===>%p \n", &a);
  printf("4 ===>%p \n", &a[0]);
  printf("5 ===>%p \n", &p);    /// address of p
  printf("6 ===>%p \n", *(&p)); // derefrencing the address where p is stored

  //////////////////////////////////
  printf("7 ===>%d \n", *(a)); //since a is the name of array and the pointer of the first element, *a == a[0]
  printf("8 ===>%d \n", a[0]); // c give us this nice option to print values in array
  printf("9 ===>%d \n", *(&a[0]));
  printf("10 ===>%d \n", *p);
  printf("11 ===>%d \n", p[0]);
  printf("12 ===>%d \n", *(*(&p))); // derefrencing the address where p is stored  to get the value of p (another address) then derefrencing that address to get the value
  printf("13 ===>%d \n ", *(a + 1));
  printf("14 ===>%d \n ", *(a + 1));
  return 0;
}