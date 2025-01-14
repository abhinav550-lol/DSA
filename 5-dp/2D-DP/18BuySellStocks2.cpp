/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

/*
Appraoch : 
Here, we use the include-exclude method, we keep a boolean to track whether a stock was bought in the previous call 
if it was not, then we have two choices -> 
1) Buy the current stock price 
2) ignore the current stock price 

in first case, we are buying so we are reducing the profit that could be gained so we subtract the current price and also mark the boolean true for the next call.
in second case , we are skipping the current buy price so we dont mark the stockBought true.
then, we store the maximum of both.

if it was, then also we have two choices -> 
1) Sell the stock at the current price 
2) ignore the current stock price 

here ,also same like buying but here we reset the stockBought to false for the next call as we can buy the same stock multiple , if we sell it before buying.
*/

//Recursion 
class Solution {
    int solve(int index, bool stockBought, vector<int> &prices){
        if(index >= prices.size()){
            return 0;
        }
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] + solve(index+1 , 1 , prices));
            int skip = (solve(index+1 , 0 , prices));
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] + solve(index+1 , 0 , prices));
            int skip = solve(index+1 , 1 , prices);
            profit = max(sell , skip);
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0, false , prices );
    }
};

//Memoization 
class Solution {
    int solve(int index, bool stockBought, vector<int> &prices, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][stockBought] != -1){
            return dp[index][stockBought];
        }
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] + solve(index+1 , 1 , prices, dp));
            int skip = (solve(index+1 , 0 , prices, dp));
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] + solve(index+1 , 0 , prices, dp));
            int skip = solve(index+1 , 1 , prices, dp);
            profit = max(sell , skip);
        }
        return dp[index][stockBought] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int> (2 , -1));
        return solve(0, false , prices, dp );
    }
};

//Tabulation 
class Solution {
    int solve( vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int> (2 , 0));
        for(int index=n-1 ;  index >= 0 ; index -- ){
            for(int stockBought = 1 ; stockBought >= 0 ; stockBought -- ){
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] +dp[index+1][1]);
            int skip = (dp[index+1][0]);
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] +dp[index+1][0]);
            int skip = dp[index+1][1];
            profit = max(sell , skip);
        }
        dp[index][stockBought] = profit;
            }
        }
        return dp[0][0];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve( prices );
    }
};

//Space Optimzation 
class Solution {
    int solve( vector<int> &prices){
        int n = prices.size();
        
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index=n-1 ;  index >= 0 ; index -- ){
            for(int stockBought = 1 ; stockBought >= 0 ; stockBought -- ){
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] +next[1]);
            int skip = (next[0]);
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] +next[0]);
            int skip = next[1];
            profit = max(sell , skip);
        }
        curr[stockBought] = profit;
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve( prices );
    }
};
