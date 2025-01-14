#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a , int b){
    return ((a%MOD) + (b%MOD))%MOD;
}

int multiply(int a, int b){
    return ((a%MOD) *1LL * (b%MOD))%MOD; // FIX RANGE ISSUES
}


int solve(int n ,int k, vector<int>& dp){
    if(n == 1 ){
        return k;
    }
    if(n == 2){
        return add(k , multiply(k , k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = multiply(k-1, add(solve(n-2, k, dp) , solve(n-1,k, dp )));
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
   return solve(n , k, dp);
}
//Tabulation 
#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a , int b){
    return ((a%MOD) + (b%MOD))%MOD;
}

int multiply(int a, int b){
    return ((a%MOD) *1LL * (b%MOD))%MOD;
}


int solve(int n ,int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k , multiply(k, k-1));
    for(int i=3 ; i<= n ; i++){
        dp[i] =multiply(( k-1) , (add(dp[i-1] , dp[i-2])));
    }
    return dp[n];
}

int numberOfWays(int n, int k) {
   return solve(n , k);
}
//Space optimization 
#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a , int b){
    return ((a%MOD) + (b%MOD))%MOD;
}

int multiply(int a, int b){
    return ((a%MOD) *1LL * (b%MOD))%MOD;
}


int solve(int n ,int k){
    int prev2 = k;
    int prev1 = add(k , multiply(k , k-1));
    for(int i=3 ; i<=n ; i++){
        int curr = multiply((k-1),(add(prev1 , prev2)));
        prev2 = prev1 ;
        prev1 = curr;
} 
    return prev1;
}

int numberOfWays(int n, int k) {
   return solve(n , k);
}
