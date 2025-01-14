//Recursion 

#include <bits/stdc++.h> 
#define MOD 1000000007
int countDistinctWays(int nStairs) {
    if(nStairs < 0){
        return 0;
    }
    
    if(nStairs == 0){
        return 1;
    }

    return countDistinctWays(nStairs - 1 ) + countDistinctWays(nStairs - 2) % MOD;
}

// top - down 

#include <bits/stdc++.h> 
#define MOD 1000000007

int solve(int nStairs, vector<int> &dp){
    if(nStairs < 0 ){
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }
    if(dp[nStairs] != -1){
        return dp[nStairs];
    }
    dp[nStairs] = solve(nStairs -1, dp) + solve(nStairs - 2, dp);
    return dp[nStairs] ;
}

int countDistinctWays(int nStairs) {
   vector<int> dp(nStairs+1, -1);
    return solve(nStairs , dp) % MOD;
}