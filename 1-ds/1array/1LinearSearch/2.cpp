//sum of an array
#include <iostream>
using namespace std;
 
int main(){
   int arr[10];
   for(int i=0;i<10;i++){
    cout<<"Enter element "<<i+1<<":  ";
    cin>>arr[i];
   }
   int sum=0;
   for(int i=0;i<10;i++){
    sum+=arr[i];
   }
   cout<<"The sum of the array is"<<sum<<endl;
  return 0;
}