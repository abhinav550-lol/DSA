//reverse an array
#include <iostream>
using namespace std;
 
int main(){
   int arr[8]={1,2,3,4,5,6,6,7};
   int size=8;

    int start=0,end=7;
   for(int i=0;i<size;i++){
    if(start>end){
        break;
    }
     int temp=arr[start];
     arr[start]=arr[end];
     arr[end]=temp;
     start++;
     end--;
   }
    for(int i=0;i<size;i++){
      cout<<arr[i]<<" ";
    }
  return 0;
}