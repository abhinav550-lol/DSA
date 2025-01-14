//unique element 
#include <iostream>
using namespace std;
int findUniqueElement(int arr[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        int checker = arr[i], count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == checker)
            {
                count++;
            }

        }
                    if (count == 1)
            {
                return arr[i];
            }
    }    
    return -1;
}

void arrayElementsTC(int arr[],int size){

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
}

int main()
{
    int testCases;
    cin >> testCases;
    for(int i=0;i<testCases;i++){
    int size;
    cin >> size;
    int arr[size];
    arrayElementsTC(arr,size);
    cout << findUniqueElement(arr, size) <<endl;
    }
    return 0;
}