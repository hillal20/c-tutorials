#include <stdio.h>

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
    while (j >= 0 && arr[j] > key) // current < previous
    {
      arr[j + 1] = arr[j]; /// next is the current
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[])
{
  int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);
  printArray(arr, n);

  return 0;
}
// function insertionSort(arr)
// {
//   for (let i = 1; i < arr.length; i++)
//   {
//     const key = arr[i];
//     let j = i - 1;
//     for (; j >= 0; j--)
//     {
//       if (arr[j] < key)
//       {
//         console.log(arr[j], key) break;
//       }

//       arr[j + 1] = arr[j];
//     }
//     arr[j + 1] = key;
//   }
//   return arr
// }

// insertionSort([ 100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79 ])