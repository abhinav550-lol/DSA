/*
Buy and sell stocks with a transcation fee
*/

//Tabulation
class Solution {
        int solve(int index, bool stockBought, vector<int> &prices, int fee ,vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][stockBought] != -1){
        return dp[index][stockBought];
        }
        int profit = 0;
        if(!stockBought){
            int buy = (-prices[index] + solve(index+1 , 1 , prices, fee, dp));
            int skip = (solve(index+1 , 0 , prices, fee, dp));
            profit = max(buy , skip);
        }else{
            int sell = (+prices[index] + solve(index+1 , 0 , prices, fee, dp) - fee );
            int skip = solve(index+1 , 1 , prices, fee, dp);
            profit = max(sell , skip);
        }
        return dp[index][stockBought] =  profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int> (2 , -1));
        return solve(0, false , prices , fee, dp );
    }
};