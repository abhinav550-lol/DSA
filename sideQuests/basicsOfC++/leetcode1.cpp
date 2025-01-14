#include <iostream>
using namespace std;
 
 int reversed(int a){
    int reversedVar=0;
    while(a!=0){
    int lastdigit=a%10;
    
    if(reversedVar>INT64_MAX/10 || reversedVar<INT64_MIN/10){
        return 0;
    }
    reversedVar=reversedVar*10+lastdigit;
    a=a/10;
    }
    return reversedVar;
 }




int main(){
 int n;
 cin>>n;
 cout<<reversed(n);
  return 0;
}