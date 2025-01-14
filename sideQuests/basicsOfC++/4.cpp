//setbits
#include <iostream>
using namespace std;
 
 void setBits(int a,int b){
    int setBit=0;
    while (a!=0 && b!=0){
      if(a&1 ){
        setBit++;
      }
        a=a>>1;
      if(b&1 ){
        setBit++;
      }
        b=b>>1;

    }
    cout<<setBit;
 }


int main(){
   int a,b;
   cin>>a>>b;
   setBits(a,b)    ;
  return 0;
}