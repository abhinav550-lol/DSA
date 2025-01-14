// interesect of 2 arrays
#include <iostream>
using namespace std;
 
 void findIntersect(int arr[],int arr2[],int size1,int size2){
    for(int i=0;i<size1;i++){
        int check=arr[i];
        for(int j=0;j<size2;j++){
            if(check==arr2[j]){
                cout<<check<<" ";
                arr2[j]=__INT_MAX__;
                break;
            }
        }
    }

 }


int main(){
    int array[10]={1,2,10,23,44,2,6789,33,34,3};
    int array2[10]={122,123,232,345,6789,433,21,33,1,2};
    findIntersect(array,array2,10,10);
  return 0;
}