#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << ' ';
  }
}

void mergeSortedArrays(int arr1[], int n, int arr2[], int m)
{
  int firstZero;
  for (int i = 0; i < n; i++)
  {
    if (arr1[i] == 0)
    {
      firstZero = i;
      break;
    }
  }
  for (int i = firstZero; i < n; i++)
  {
    swap(arr1[i], arr2[i - firstZero]);
  }
  for (int i = firstZero; i < n; i++)
  {
    int currentElement = arr1[i], j = i - 1;
    while (j >= 0 && arr1[j] > currentElement)
    {
      arr1[j + 1] = arr1[j];
      j--;
    }
    arr1[j + 1] = currentElement;
  }

  printArray(arr1, n);
}

int main()
{
  int arr1[] = {1, 3, 5, 7, 0, 0, 0}, arr2[] = {2, 4, 6};
  int n = sizeof(arr1) / sizeof(arr1[0]), m = sizeof(arr2) / sizeof(arr2[0]);
  mergeSortedArrays(arr1, n, arr2, m);
  return 0;
}