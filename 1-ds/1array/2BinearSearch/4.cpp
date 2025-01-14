// pivot = 1 (min value)
#include <iostream>
using namespace std;
 
int pivot(int arr[],int size){
    int start=0,end=size-1;
    int mid=start+(end-start)/2;
    while(start<end){
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }else{
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int main(){
   int arr[5]={4,5,1,2,3};
   cout<<pivot(arr,5);
  return 0;
}