// duplicate
#include <iostream>
using namespace std;
 
 int findDuplicate(int arr[],int size){
    for(int i=0;i<size;i++){
        int check=arr[i];
        for(int j=0;j<size;j++){
            if(i!=j){
            if(check==arr[j]){
                return check;
            }
            }
        }
    }
    return -1;
 }

int main(){
       int arr[]={1,2,3,4,5,6,7,1};
       cout<<findDuplicate(arr,8);
  return 0;
}