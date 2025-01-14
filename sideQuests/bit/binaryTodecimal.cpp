#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
   int a;
   cin>>a;
  //101
  int decimal=0, i=0;
  
  while(a!=0){
    int setBit=a%10;
    if(setBit==1){
      decimal+=pow(2,i);
    }
    i++;
    a/=10;
  }    
  cout<<decimal;
  return 0;
}