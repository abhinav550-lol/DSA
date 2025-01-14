//optimzied of 5
#include <iostream>
using namespace std;
int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[5] = {0, 1, 0, 1, 2};
    cout << findUnique(arr, 5);
    return 0;
}