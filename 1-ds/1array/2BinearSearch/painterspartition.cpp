#include <iostream>
using namespace std;
 
 bool solPossible(int arr[],int size,int painters,int time,int mid){
    int rounds=1,partition=0;
    for(int i=0;i<size;i++){
        if((partition+(arr[i]*time))<=mid){
            partition+=(arr[i]*time);
        }else{
          rounds++;
          if(rounds>painters || arr[i]>mid){
            return false;
          }
        partition=arr[i];
        }
    }
    return true;
 }



 int minTimeToPaint(int arr[],int size,int painters,int time){
    int start=0,end=0,ans;
    for(int i=0;i<size;i++)
        end+=(time*arr[i]);

   while(start<=end){
    int mid=start+(end-start)/2;
    if(solPossible(arr,size,painters,time,mid)){
      if(ans>mid){ans=mid;}
       end=mid-1;
    }else{
       start=mid+1;
    }

   }
   return ans;
 }

int main(){
    int arr[]={5,5,5,5,5},size=sizeof(arr)/sizeof(arr[0]);
   int time,painters;    
   cin>>time>>painters;
   cout<<minTimeToPaint(arr,size,painters,time);
  return 0;
}