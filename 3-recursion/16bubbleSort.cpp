#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void bubbleSort(int *arr,int j){
    int i=0;
    bool c = false;
    if(j<=0) return ;
    while(i<j){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            c = true;
        }                   
        i++;
    }
    if(c==false) return ;
    bubbleSort(arr,j-1);
 }

int main(){
   int arr[5]={9,10,19,4,3};
   bubbleSort(arr,4);
   for(int elem:arr){
    cout<<elem<<' ';
   }
  return 0;
}