#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int findFib(int n,vector<int> &dp){
    if(n == 0 || n == 1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = findFib(n-1 , dp) + findFib(n-2 , dp);
    return dp[n];
}

int findFibNum(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return findFibNum(n-1)+findFibNum(n-2);
}

int main(){
   int n;
   cin >> n; 
    //recursion tc-o(n + n) sc - o(n + n)
    cout << findFibNum(n) << endl;

   //top-down apporach tc - o(n) sc- o(n + n)
    vector<int> dp(n+1 , -1);
    cout << findFib(n , dp) << endl;

    //bottom-up approach tc - o(n) sc - o(n)
    vector<int> DP(n+1 , -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i<= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;

    //space optimization tc - o(n) sc - o(1)
    int prev1 = 1;
    int prev2 = 0;
    int curr = prev1 + prev2;
    for(int i=2 ;  i<= n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << curr << endl;
  return 0;
}