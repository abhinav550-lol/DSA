#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[][4], int m, int n, int q)
{
    int start = 0, end = m * n - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        int element = arr[mid / n][mid % n];
        if (element == q){
            return true;
        }
            if (element < q){ 
                start = mid + 1;
            }else
                end = mid - 1;
            
        
    }
    return 0;
}

int main()
{
    int arr[3][4] = {{1, 3, 5, 7},
                     {10, 11, 16, 20},
                     {23, 30, 34, 60}};
    int target;
    cin>>target;
    cout << binarySearch(arr, 3, 4, target);
    return 0;
}