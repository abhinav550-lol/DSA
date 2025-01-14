// all duplicate
#include <iostream>
using namespace std;
 
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

 void findAllDuplicates(int arr[],int size){
    int c=0,arr2[100];
    for(int i=0;i<size;i++){
        int check=arr[i];
        for(int j=0;j<size;j++){
            if(i!=j){
            if(check==arr[j]){
          
                          arr2[c]=check;
                          arr[j]==__INT_MAX__;
                          check=__INT8_MAX__;
                             c++;
                             break;
            
              
            }
            }
        }
    }
    printArray(arr2,c);
 }

int main(){
       int arr[]={1,2,3,4,5,6,8,8,9,9,7,1,7};
       findAllDuplicates(arr,13);
  return 0;
}