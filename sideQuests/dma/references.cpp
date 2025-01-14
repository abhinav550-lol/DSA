#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int updateVal(int& n){
    n=n+1;
}
int main(){
   int i=5;
   int &j=i;
   j++;
   updateVal(j);
   cout<<i;    
  return 0;
}