//Rcursion + Memo
class Solution {
        int solve(int index, bool stockBought, int transactionCount ,vector<int> &prices,vector<vector<vector<int>>> &dp, int k){
        if(index >= prices.size() || transactionCount == k){
            return 0;
        }
        if(dp[index][stockBought][transactionCount] != -1){
            return dp[index][stockBought][transactionCount];
        }
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] + solve(index+1 , 1 , transactionCount , prices, dp, k));
            int skip = (solve(index+1 , 0 ,transactionCount , prices, dp, k));
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] + solve(index+1 , 0 , transactionCount + 1 , prices, dp, k));
            int skip = solve(index+1 , 1, transactionCount , prices, dp, k);
            profit = max(sell , skip);
        }
        return dp[index][stockBought][transactionCount] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 ,vector<int>(k+1 , -1)));
        return solve(0, false , 0,  prices, dp, k );
    }
};

//Tabulation 
class Solution {
    int solve(vector<int> &prices, int n, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int index = n-1; index >= 0; index--) {
            for(int stockBought = 0; stockBought <= 1; stockBought++) {
                for(int transactionCount = 0; transactionCount <= k-1; transactionCount++) {
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
    int maxProfit(int k,  vector<int> &prices) {
        int n = prices.size();
        return solve(prices, n, k);
    }
};
//This can be space optimzed using the 2*k where we set the sell and buy and trancstion within only 2D array 