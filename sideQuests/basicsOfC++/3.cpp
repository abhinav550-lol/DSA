// ncr

#include <iostream>
using namespace std;
 
int factorial(int a){
   if(a==1 || a==0){
    return 1;
   }
   else{
   return (a)*factorial(a-1);
   }
}

int nCr(int n,int r){
    int nCofr=factorial(n)/(factorial(r)*factorial(n-r));
    return nCofr;
}

int main(){
   int n,r;
   cin>>n>>r;
   cout<<nCr(n,r);    
  return 0;
}