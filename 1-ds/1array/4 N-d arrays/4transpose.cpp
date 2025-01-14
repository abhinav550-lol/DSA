#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 void printArray(int arr[][3],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
 }

 void transpose(int arr[][3],int m,int n){
    printArray(arr,m, n);
    cout<<endl;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++)  {
        if(i==j)
            break;
        swap(arr[i][j],arr[j][i]);
      }
    }
    printArray(arr,m, n);
 }


int main(){
   int arr[3][3]={{1,2,3},
                  {4,5,6},
                   {7,8,9}} ;   
  transpose(arr,3,3);
  return 0;
}