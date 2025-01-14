//first and last occurence of an element
#include <iostream>
using namespace std;
 
 int lastOccurence(int arr[],int size,int query){
  int start=0,end=size-1;
  int mid=start+(end-start)/2;
  int last=-1;
  while(start<=end){
    if(arr[mid]==query){
      last=mid;
      start=mid+1;
    }else if(arr[mid]>query){
      end=mid-1;
    }else if(arr[mid]<query){
      start=mid+1;
    }
    mid=start+ (end-start)/2;
  }
  return last;
 }
int firstOccurence(int arr[], int size ,int query){
   int start=0,end=size-1;
   int mid = start+ (end-start)/2;
   int first=-1;
   while(start<=end){
     if(arr[mid]==query){
      first = mid;
      end=mid-1;
     }else if(arr[mid]>query){
      end=mid-1;
     }else if(arr[mid]<query){
     start = mid+1;
     }
     mid=start+ (end-start)/2;
     
   }
   return first;
}
int totalNumberOfOccuernces(int arr[],int size,int query){
  int total=(lastOccurence(arr,size,query)-firstOccurence(arr,size,query))+1;
  return total;
}

int main(){
   int arr[6]={0,3,3,3,3,4};
   cout<<firstOccurence(arr,6,3)<<endl;
   cout<<lastOccurence(arr,6,3)<<endl;
   cout<<totalNumberOfOccuernces(arr,6,3);
  return 0;
}