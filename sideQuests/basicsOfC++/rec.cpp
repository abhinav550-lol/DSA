#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void r(int n){
    if(n<=0) return ;

    cout<<n;

    r(n-1);
    r(n-2);
}

int main(){
   int n =4 ;
   r(4);
  return 0;
}