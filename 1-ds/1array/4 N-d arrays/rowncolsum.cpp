#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void rowSum(int arr[][4],int m , int n){
    for(int i=0;i<m;i++){
            int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[i][j];
        }
        cout<<"sum of row "<<i+1<<": "<<sum<<endl;
    }
 }

void colSum(int arr[][4],int m,int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=arr[j][i];
        }
        cout<<"sum of col "<<i+1<<": "<<sum<<endl;
    }
}

int main(){
   int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//    rowSum(arr,3,4);
   colSum(arr,3,4);
   return 0;
}