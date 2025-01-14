#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void wavePrint(int arr[][4], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[j][i] << ' ';
            }
        }
        if (i % 2 != 0)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[j][i] << ' ';
            }
        }
    }
}
int main()
{
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};

    wavePrint(arr, 3, 4);
    return 0;
}