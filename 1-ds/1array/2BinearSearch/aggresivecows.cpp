#include <iostream>
using namespace std;

void sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int currentElement = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > currentElement)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currentElement;
    }
}

 bool solPossible(int arr[],int size,int cows,int mid){
    int cowCount=1,lastPlaced=arr[0];
    for(int i=1;i<size;i++){
        if((arr[i]-lastPlaced)>=mid){
            lastPlaced=arr[i];    
            cowCount++;
        }
        if(cowCount>=cows){
                return true;
            }
    }
    return false;
 }

int LargestmaxStallPos(int arr[], int size, int cows)
{
    sort(arr, size);
    int start = 0, end = (arr[size-1]-arr[0]),ans=-1;
    while(start <= end){
        int mid=start+(end-start)/2;
        if(solPossible(arr,size,cows,mid)){
            if(ans<mid){ans=mid;}
       start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return end;
}

int main()
{
    int arr[] = {9,1,10,3,5}, size = sizeof(arr) / sizeof(arr[0]);
    int cows;
    cin >> cows;
    cout<<LargestmaxStallPos(arr, size, cows);
    return 0;
}