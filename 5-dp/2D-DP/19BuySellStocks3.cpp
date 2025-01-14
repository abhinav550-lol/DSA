/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

//Recursion + Memo
class Solution {
    int solve(int index, bool stockBought, int transactionCount ,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(index >= prices.size() || transactionCount == 2){
            return 0;
        }
        if(dp[index][stockBought][transactionCount] != -1){
            return dp[index][stockBought][transactionCount];
        }
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] + solve(index+1 , 1 , transactionCount , prices, dp));
            int skip = (solve(index+1 , 0 ,transactionCount , prices, dp));
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] + solve(index+1 , 0 , transactionCount + 1 , prices, dp));
            int skip = solve(index+1 , 1, transactionCount , prices, dp);
            profit = max(sell , skip);
        }
        return dp[index][stockBought][transactionCount] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 ,vector<int>(3 , -1)));
        return solve(0, false , 0,  prices, dp );
    }
};

//Tabulation 
class Solution {
    int solve(vector<int> &prices, int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int index = n-1; index >= 0; index--) {
            for(int stockBought = 0; stockBought <= 1; stockBought++) {
                for(int transactionCount = 0; transactionCount <= 1; transactionCount++) {
                    int profit = 0;
                    if(stockBought == 0) {
                        int buy = -prices[index] + dp[index+1][1][transactionCount];
                        int skip = dp[index+1][0][transactionCount];
                        profit = max(buy, skip);
                    } else {
                        int sell = prices[index] + dp[index+1][0][transactionCount+1];
                        int skip = dp[index+1][1][transactionCount];
                        profit = max(sell, skip);
                    }
                    dp[index][stockBought][transactionCount] = profit;
                }
            }
        }
        return dp[0][0][0];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, n);
    }
};

//Space Optimzation is also possbile, it has the same patten of next and curr