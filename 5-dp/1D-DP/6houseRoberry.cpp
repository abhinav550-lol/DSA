/*

Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.



All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.



You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

*/
#include <bits/stdc++.h> 
long long int solve(vector<int> nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int incl = nums[i] + prev2;
        int excl = prev1;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();

    if (n == 1) return valueInHouse[0];

    vector<int> firstOne;
    vector<int> lastOne;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            firstOne.push_back(valueInHouse[i]);
        }
        if (i != 0) {
            lastOne.push_back(valueInHouse[i]);
        }
    }
    
    long long int sol1 = solve(firstOne, n - 1);
    long long int sol2 = solve(lastOne, n - 1);
    return max(sol1, sol2);
}