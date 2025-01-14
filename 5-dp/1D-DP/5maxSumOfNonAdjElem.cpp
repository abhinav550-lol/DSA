// recursion 
#include <bits/stdc++.h>
int solve(vector<int> nums, int n){
    if(n == nums.size() -1)
        return nums[n];
    if(n >= nums.size()){
        return 0;
    }    
    int inclusion = solve(nums , n+2) + nums[n];
    int exclusion = solve(nums , n+1) + 0;

    return max(inclusion , exclusion);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solve(nums , 0);
    return ans;
}

//memo
int solve(vector<int> nums , int n , vector<int> &dp){
    if(n == nums.size()-1 ){
        return nums[n];
    }
    if(n >= nums.size() - 1){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int include = solve(nums , n+2 , dp) + nums[n];
    int exclude = solve(nums , n+1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    int ans = solve(nums , 0 ,dp);
    return ans;
}

//tabulation 
int solve(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n , 0);

    dp[0] = nums[0];

    for(int i = 1; i < n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;

        dp[i] = max(incl , excl);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solve(nums);
    return ans;
}

//space optimization 
int solve(vector<int> nums){
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans =  max(incl , excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solve(nums);
    return ans;
}