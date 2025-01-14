//Recursion 
#include <bits/stdc++.h>

int solve(vector<int> num , int x){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0 ; i<num.size() ; i++){
         int ans = solve(num , x-num[i]);
         if(ans != INT_MAX){
             mini = min(ans+1 , mini);
         }
    }
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    int minCoins = solve(num , x);
    
    return minCoins == INT_MAX ? -1 : minCoins ;
}

//Memo + Recur


int solve(vector<int> num , int x, vector<int> &dp){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }
    if(dp[x ] != -1){
        return dp[x];
    }
    int mini = INT_MAX;
    for(int i=0 ; i<num.size() ; i++){
        int ans = solve(num , x-num[i] , dp);
        if(ans != INT_MAX){
            mini = min(1+ans , mini);
        }
    }
    dp[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, -1);
    int minCoins = solve(num , x, dp);
    return minCoins == INT_MAX ? -1 : minCoins ;
}

//bottom up

#include <bits/stdc++.h>

int solve(vector<int> num, int x) {
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < num.size(); j++) {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(1 + dp[i - num[j]], dp[i]);
            }
        }
    }
    
    if (dp[x] == INT_MAX) {
        return -1;
    }
    
    return dp[x];
}

    int minimumElements(vector<int> &num, int x)
    {
        int minCoins = solve(num , x);
        return  minCoins ;
    }

