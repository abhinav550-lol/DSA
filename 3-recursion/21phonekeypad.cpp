#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void solution(string digits,vector<string> &res, string subres , vector<string>keypad, int index){
         if(index>=digits.length()) {
            res.push_back(subres);
            return ;
         }

         int num = digits[index] - '0';
         string val = keypad[num];
         for(int i=0;i<val.length();i++){
        subres.push_back(val[i]);
        solution(digits,res,subres,keypad,index+1);
        subres.pop_back();
         }

    }   

 vector<string> phoneKeypadResult(string digits){
    vector<string> res;
    if(res.length()==0) return 0;
    string subRes;
    int index = 0;
    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solution(digits,res,subRes,keypad,index);
    return res;
 }

int main(){
   string digits = "23";
   vector<string> result = phoneKeypadResult(digits);
   for(string i: result) cout<<i<<' ';
  return 0;
}