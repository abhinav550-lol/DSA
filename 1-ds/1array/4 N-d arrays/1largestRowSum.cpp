#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int rowSum(int arr[][4],int m , int n){
    int largestRowSum=INT_MIN;
    for(int i=0;i<m;i++){
            int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[i][j];
        }
       if(largestRowSum<sum){
        largestRowSum=i;
       }
    }
    return largestRowSum;
 }

int main(){
   int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
   cout<<rowSum(arr,3,4);
   return 0;
}