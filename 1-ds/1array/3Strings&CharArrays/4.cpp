
#include <iostream>
#include<cstring>
using namespace std;

bool isan(char s){
    if(s>='0' && s<='9' || s>='a' && s<='z' ){
         return 1;
    }
    return 0;
}

string toLowerCase(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
        s[i]=(s[i]-'A')+'a';
        }
    }
    return s;
}

bool checkPalindrome(string c){
    c=toLowerCase(c);
   int start=0,end=c.length()-1;
   while(start<=end){
        if(isan(c[start])==0){
            start++;
        }
       if(isan(c[end])==0)
            end--;
        
      if(isan(c[start])&&isan(c[end])){
          if(c[start]!=c[end])
              return false;
              
            start++;
            end--;
      }
     
   }
   return true;
}


int main(){
    string s;
    getline(cin,s);
    cout<<checkPalindrome(s);
    return 0;
}
 