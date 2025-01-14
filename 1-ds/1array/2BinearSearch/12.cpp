#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
 
 void printVector(vector <int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
 }

 void arraySum(vector<int> &v1,vector<int>&v2,vector<int>&v3){
    int n=v1.size(),m=v2.size();
    int num1=1,num2=1,num3;
    int i=0;
    while(n-- && m--){
        num1+=(v1[n]*pow(10,i));
        num2+=(v2[m]*pow(10,i));
        i++;
    }
      num3=num1+num2;
      while(i!=0){
        float divisor=pow(10,(i-1));
        int digit=num3/divisor;
        num3%=(int)divisor;
        v3.push_back(digit);
        i--;
      } 
 printVector(v3);
 }

int main(){
   vector<int> v1={6,3,5},v2={2,8,6};
   vector <int> v3;
   arraySum(v1,v2,v3);

  return 0;
}
// correct ans
// vector<int> reverse(vector<int> v) {
    
//     int s = 0;
//     int e = v.size()-1;
    
//     while(s<e)
//     {
//         swap(v[s++], v[e--]);
//     }
//     return v;
// }

// vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
//     int i = n-1;
//     int j = m-1;
//     vector<int> ans;
//     int carry = 0;
    
//     while(i>=0 && j>=0) {
//         int val1 = a[i];
//         int val2 = b[j];
            
//         int sum = val1 + val2 + carry;   
        
//         carry = sum/10;
//         sum = sum%10;
//         ans.push_back(sum);
//         i--;
//         j--;
//     }
    
//     // first case
//     while(i>=0) {
//         int sum = a[i] + carry;
//         carry = sum/10;
//         sum = sum%10;
//         ans.push_back(sum);
//         i--;
//     }
    
//      // second case
//     while(j>=0) {
//         int sum = b[j] + carry;
//         carry = sum/10;
//         int value = sum%10;
//         ans.push_back(value);
//         j--;
//     }
    
//      // second case
//     while(carry != 0) {
//         int sum = carry;
//         carry = sum/10;
//         sum = sum%10;
//         ans.push_back(sum);
//     }
    
//     //print(ans);
//     return reverse(ans);
// }