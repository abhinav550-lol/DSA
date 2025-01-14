#include <iostream>
using namespace std;
 
int main(){
   int n;
   cin>>n;
    int a=0,b=1;
    n=n-2;
    cout<<a<<" "<< b<< " ";
    if(n==a || n==b){
        cout<<n;
    }else{
  for(int i=1;i<=n;i++){
      int nextNum=a+b;
      cout<<nextNum<<" ";
      a=b;
      b= nextNum;
    }
    }
    

   
  
  return 0;
}