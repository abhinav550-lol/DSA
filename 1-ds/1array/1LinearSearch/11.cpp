//sort 0,1
#include <iostream>
using namespace std;
 
 void sortZerosAndOnes(int arr[],int size){
    int i=0,j=size-1;
    while(i<=j){
        if(arr[i]==0){
            i++;
        }
        if(arr[j]==1){
            j--;
        }
        if(arr[j]==0 && arr[i]==1 && i<j){
            arr[j]=1;
            arr[i]=0;
            i++;
            j--;
        }
    }
 }
 void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<' ';
    }
 }

int main(){
   int arr[]={0,1,1,0,0,1,1,0,1,0};
   sortZerosAndOnes(arr,10);
   printArray(arr,10);
  return 0;
}