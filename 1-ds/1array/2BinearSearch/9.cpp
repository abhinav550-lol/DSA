#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}
void sortZerosToRight(int arr[], int size)
{
        int s=0;
    for(int i=0;i<size;i++){
        if(arr[i]!=0 ){
        swap(arr[s++],arr[i]);
        }
    }
    printArray(arr,size);
}

int main()
{
    int arr[] = {0,4,0,0,0,0,1,0,3,0,0,0,0,0,0,3 ,12,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortZerosToRight(arr, n);
    return 0;
}