// peak element of mountain array
#include <iostream>
using namespace std;
 
 int peakElement(int arr[],int size){
    int start=0,end=size-1;
    int mid = start+(end-start)/2;
    while(start<end){
       if(arr[mid]<arr[mid+1]){
        start=mid+1;
       }else{
        end=mid;
       }
        mid=start+ (end-start)/2;
    }
    return start;
 }

int main(){
   int arr[7]={1,2,10,7,5,4,3};
   cout<<peakElement(arr,7);
  return 0;
}