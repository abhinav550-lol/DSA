// find pivot element of array where left sum == right sum

#include <iostream>
using namespace std;
 
 int pivotElement(int arr[],int size){
    int start=0,end=size-1,perm=end;
    int mid=start+(end-start)/2;
    while(start<=end){
        int leftSum=0,rightSum=0;
        for(int i=0;i<=mid-1;i++){
           leftSum+=arr[i];
         } 
        for(int i=mid+1;i<=perm;i++){
            rightSum+=arr[i];
        }
        if(rightSum==leftSum){
            return mid;
        }else if(rightSum<leftSum){
          mid++;
        }else{
           
        }
    }
    return -1;
 }

int main(){
   int arr[7]={2,3,1,1,7,3,4};
   cout<<pivotElement(arr,7);
  return 0;
}
//ok