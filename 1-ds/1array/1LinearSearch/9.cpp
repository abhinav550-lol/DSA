//pair sum
#include <iostream>
using namespace std;
 
 void pairSum(int arr[],int size,int sum){
    for(int i=0;i<size;i++){
        int first=arr[i];
        for(int j=i+1;j<size;j++){
            int second=arr[j];
            if(first+second==sum){
                if(first<=second){
                cout<<first<<' '<<second<<endl;
                }
            }
        }
    }
 }

int main(){
   int sum,arr[10]={1,2,3,4,5,6,7,8,9,10};
   cin>>sum;
   pairSum(arr,10,sum);
  return 0;
}