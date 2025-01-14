/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
*/

/*
Approach : 
Similar to house robbery problem, where we need to exclude first or last index if either is in , then other cannot be.
here, also as we have 3n slcies and we can eat n slices , we need to use the same appraach as house robber problem but we reduce the slices we can eat when we eat one. (n-1)
*/  

//Recursion
class Solution {

    int solve(int index , vector<int> a , int k){
        if(k == 0|| index >= a.size()){
            return 0;
        }

        int inc = a[index] + solve(index + 2 , a , k-1);
        int excl = solve(index+1 , a , k);
        return max(inc , excl);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> case1(slices.begin() , slices.end() -1 );
        vector<int> case2(slices.begin()+1 , slices.end());

        int sol1 = solve(0, case1 , n/3);
        int sol2 = solve(0, case2 , n/3);
        return max(sol1, sol2) ;
    }
};

//Memo
class Solution {

    int solve(int index , int endingIndex, vector<int> a , int k, vector<vector<int>> &dp){
        if(k == 0|| index >= a.size()){
            return 0;
        }
        if(dp[k][index] != -1){
            return dp[k][index];
        }
        int inc = a[index] + solve(index + 2 , endingIndex , a , k-1, dp);
        int excl = solve(index+1 ,endingIndex, a , k, dp);
        dp[k][index] = max(inc , excl);
        return dp[k][index];
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> case1(slices.begin() , slices.end() -1 );
        vector<int> case2(slices.begin()+1 , slices.end());


        vector<vector<int>> dp1((n/3)+1 , vector<int>(n+1 , -1));
        vector<vector<int>> dp2((n/3)+1 , vector<int>(n+1 , -1));
        int sol1 = solve(0, n-2, case1 , n/3, dp1);
        int sol2 = solve(0, n-1 ,case2 , n/3, dp2);
        return max(sol1, sol2) ;
    }
};

//tab
class Solution {
    int solve(const vector<int>& slices, int start, int end, int k) {
        int n = end - start + 1;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                int inc = slices[start + i] + (i + 2 < n ? dp[j - 1][i + 2] : 0);
                int exc = dp[j][i + 1];
                dp[j][i] = max(inc, exc);
            }
        }
        return dp[k][0];
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        int case1 = solve(slices, 0, n - 2, k);
        int case2 = solve(slices, 1, n - 1, k);
        return max(case1, case2);
    }
};

//so
