#include <iostream>
using namespace std;
 
 int binarySearch(int arr[],int size,int query){
 int start=0,end=size-1;
 int mid=(start+end)/2;

  while(start<=end){
     if(arr[mid]==query){
        return mid;
      }else if(query>arr[mid]){
         start=mid+1;
        }else{
          end=mid-1;
        }
        mid=(start+end)/2;
      }
 return -1;

 }
int main(){
 int arr[10]={1,2,3,4,5,6,7,8,9,10};
 int arr2[5]={1,2,3,4,5};

 
 cout<<binarySearch(arr,10,4)<<endl;
 cout<<binarySearch(arr2,5,4)<<endl;



  return 0;
}