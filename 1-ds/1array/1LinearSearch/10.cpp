//triplet sum;
#include <iostream>
using namespace std;
 
 void tripletSum(int arr[],int size,int sum){
  for(int i=0;i<size;i++){
    int first=arr[i];
    for(int j=i+1;j<size;j++){
        int second=arr[j];
       if(first<=second){ 
        if(first+second<=sum){
            for(int k=j+1;k<size;k++){
                int third=arr[k];
                if(third>=second&&third>=first){
                if(first+second+third==sum){
                    cout<<first<<' '<<second<<' '<<third<<endl;
                    exit(0);
                }
            }
            }
        }
       }
    }
  }
 }

int main(){
   int sum,arr[]={-1,-15,-1,-1,1 };
   cin>>sum;
   tripletSum(arr,5,sum);
  return 0;
}