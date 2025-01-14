//Optimized Solution of DP with Hashing O(n)
/*
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int , int> dp;
        int ans = 0;
        for(int i=0 ; i<arr.size(); i++){
            int prevAPelement = arr[i] - difference;

            int prevAP = 0;
            if(dp.count(prevAPelement) != 0){
                prevAP = dp[prevAPelement];
            }
            dp[arr[i]] = 1+prevAP;
            ans = max(ans, 1+prevAP); 
        }
        return ans;
    }
};