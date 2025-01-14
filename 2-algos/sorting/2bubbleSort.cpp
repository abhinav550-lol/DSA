#include <iostream>
using namespace std;

  void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
    cout<<arr[i]<<' ';
    }
  }
 
 void bubbleSort(int arr[],int size){
   for(int i=1;i<size;i++){
    bool swapped=false;
    for(int j=0;j<size-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped = true;
        }
    }
     if(swapped==true)
       break;
   }
    printArray(arr,size);
 }

int main(){
    int arr[6]={10,1,7,6,14,9};
    bubbleSort(arr,6);
  return 0;
}