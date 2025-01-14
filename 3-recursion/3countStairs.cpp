#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int countDistinctWays(int n){
    if(n<0)
     return 0;
    if(n==0)
        return 1;
    
   return countDistinctWays(n-1)+countDistinctWays(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<countDistinctWays(n);
  return 0;
}