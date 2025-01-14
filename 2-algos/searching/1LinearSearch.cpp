
#include <iostream>
using namespace std;
 int find(int arr[],int size,int element){
   for(int i=0;i<size;i++){
    if(arr[i]==element){
        return i;
    }
   }
   return -1;
 }
int main(){
    int array[10]={1,2,3,4,5,6,7,8,9,10},query;
    cin>>query;
    cout<<find(array,10,query);
  return 0;
}