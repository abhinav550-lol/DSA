#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
}

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int currentPos = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[currentPos] > arr[j])
            {
                currentPos = j;
            }
        }
        swap(arr[currentPos], arr[i]);
    }
    printArray(arr, size);
}

int main()
{
    int arr[5] = {64, 25, 11, 22, 8};
    SelectionSort(arr, 5);

    return 0;
}