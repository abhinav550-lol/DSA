/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.


*/

/*
Approach :
we cant do it like picking min price and then check for next biggest price hike. this will create problem when test cases are like:
[2 , 4 ,1] 

we know we cant sell before buying so, 
we can start from 0
and check for max profit in range of (1 to n-1)
while updating the buying price
*/
//o(n) o(1) tc and sc
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int buyPrice = arr[0];
        int n = arr.size();
        int profit = INT_MIN;
        for(int i = 1 ; i < n ; i++){
            int diff = arr[i] - buyPrice;
            profit = max(profit , diff);
            buyPrice = min(arr[i] , buyPrice);
        }
        return profit;
    }
};