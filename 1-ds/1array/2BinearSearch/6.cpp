//Square root using binary search
#include <iostream>
using namespace std;
 
 int SquareRoot(int a){
    int start=0,end=a,ans;
        int mid=start+(end-start)/2;
    while(start<=end){
        if((mid*mid)<=a){
            ans=mid;
            start=mid+1;
        }else{
           end=mid-1;
        }
            mid=start+(end-start)/2;
    }
    return ans;
 }

int main(){
  
   int num;
   cin>>num;
   cout<<SquareRoot(num);
  return 0;
}