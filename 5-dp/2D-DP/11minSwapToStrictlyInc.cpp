/*
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].
*/

/*
Appraoch :
we dont mutate the array. so we use 3 variables swappped , prev1 , prev2 

prev1 is element prev to the nums1 index
prev2 is element prev to the nums2 index
swapped ensure that we know that the prev elements were swapped or not.


*/


//Recursion
class Solution {
    int solve(int index, vector<int> nums1 , vector<int> nums2 , int n , bool swapped){
        if(index >= n){
            return 0;
        }
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped){
            swap(prev1 , prev2);
        }
        int ans = INT_MAX;
        if(prev1 < nums1[index] && prev2 < nums2[index]){
            ans = min(ans , solve(index+1, nums1, nums2, n , 0));
        }
        if(prev1 < nums2[index] && prev2 < nums1[index]){
            ans = min(ans , 1 + solve(index+1, nums1, nums2 , n , 1));
        }
    return ans;
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n= nums1.size();
        return solve(1, nums1, nums2 , n , 0);
    }
};

//Memo
class Solution {
    int solve(int index, vector<int>& nums1, vector<int>& nums2, bool swapped, vector<vector<int>>& dp) {
        if (index >= nums1.size()) {
            return 0;
        }
        if (dp[index][swapped] != -1) {
            return dp[index][swapped];
        }
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        if (swapped) {
            swap(prev1, prev2);
        }
            int ans = INT_MAX;
            if (prev1 < nums1[index] && prev2 < nums2[index]) {
                ans = min(ans, solve(index + 1, nums1, nums2, 0, dp));
            }
            if (prev1 < nums2[index] && prev2 < nums1[index]) {
                ans = min(ans, 1 + solve(index + 1, nums1, nums2, 1, dp));
            }
            return dp[index][swapped] = ans;
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        return solve(1, nums1, nums2, 0, dp);
    }
};

//Tab
// NOT WORKING SOLUTION SOMEHOW EVEN THOUGH IT IS CORRECT
class Solution {
    int solve( vector<int>& nums1, vector<int>& nums2,int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int index=n-1 ; index>= 1 ; index--){
            for(int swapped = 0 ; swapped <= 1 ; swapped ++ ){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped) swap(prev1 , prev2);
                 int ans = INT_MAX;
            if (prev1 < nums1[index] && prev2 < nums2[index]) {
                ans = dp[index+1][0];
            }
            else if (prev1 < nums2[index] && prev2 < nums1[index]) {
                ans = min(ans, 1 + dp[index+1][1]);
            }
            dp[index][swapped] = ans;
            }
        }
        return dp[0][0] or dp[0][1];
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solve( nums1, nums2, nums1.size());
    }
};

//SO
