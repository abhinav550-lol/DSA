#include <iostream>
using namespace std;
 
 void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<' ';
    }
 }

void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int currentElement=arr[i],j=i-1;
        while(j>=0 && arr[j]>currentElement){
            arr[j+1]=arr[j];
            j--;
        }
            arr[j+1]=currentElement;
    }
    printArray(arr,size);
}



int main(){
   int arr[]={7,7,11,11,10,4,3,15,3};
   insertionSort(arr,9);
  return 0;
}





 
//  void insertionSort(int arr[],int size){
//     for(int i=1;i<size;i++){
//         int currentElement=arr[i];
//         int j=i-1;
//         for(;j>=0;j--){
//             if(currentElement<arr[j]){
//                 arr[j+1]=arr[j];
//             }else{
//                 break;
//             }
//         }
//                 arr[j+1]=currentElement;
//     }
//     printArray(arr,size);
//  }