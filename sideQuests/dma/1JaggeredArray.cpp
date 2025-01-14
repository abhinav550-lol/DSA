#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int rows;
  cin >> rows;
  int *size = new int[rows];

  int **arr = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    int cols;
    cin >> cols;
    size[i] = cols;
    arr[i] = new int[cols];
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < size[i]; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < size[i]; j++)
    {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}