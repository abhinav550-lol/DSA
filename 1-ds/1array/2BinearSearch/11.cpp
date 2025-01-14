#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 bool checkRotatedSortedArray(vector <int> &v){
    int count=0;
    for(int i=1;i<v.size();i++){
       if(v[i-1]>v[i]){
        count++;
       }
    }
        if(v[v.size()-1]>v[0]){
        count++;
       }
    return count<=1;
 }

int main(){
   vector <int> v={3,4,5,1,2};
   cout<<checkRotatedSortedArray(v);
  return 0;
}