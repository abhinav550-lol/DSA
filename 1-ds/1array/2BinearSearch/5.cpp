// searching in sorted rotated array
#include <iostream>
using namespace std;

int pivotElement(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[0] <= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}

int SearchInPivotedArray(int arr[], int size, int query)
{
    int pivot = pivotElement(arr, size);
    int start = 0, end = size - 1;
    
   if(query==arr[pivot]){return pivot;}

    if (arr[pivot] <= query && query <= arr[end])
    {
        start = pivot + 1;
    }
    else
    {
        end = pivot - 1;
    }
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == query)
        {
            return mid;
        }
        if (arr[mid] < query)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{

    int arr[10] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    int query;
    int testCases;
    cin >> testCases;
    
    for (int i = 0; i < testCases; i++)
    {
        cin >> query;
        cout << SearchInPivotedArray(arr, 10, query) << endl;
    }
    return 0;
}