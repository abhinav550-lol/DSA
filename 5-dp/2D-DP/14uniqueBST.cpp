/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/

/*
Approach : 
base cases :
if 0 nodes, then 1 BST (empty tree is a BST)
and if 1 node, then 1BST possible

for 1 to n , if we choose a "i" between 1 to n, then 
leftSubtree = numsTrees(i-1);
and rightSubTree = numsTrees(n-i);
eg : i 
   /  \
 i-1  n-i

 as p&c , we know i-1 and n-i are incomplete events so multiply them
 and now, we add all the solutions to the ans for every i ranging in 1 to n, then we have our answer.
*/


//Recursion 
class Solution {
public: 
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }
        return ans;
    }
};
//Memo
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            ans += solve(i-1, dp) * solve(n-i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n){
        vector<int> dp(n+1, -1);
        return solve(n , dp);
    }
};
//Bottom Up
class Solution {
public:
    int solve(int n) {
        vector<int> dp(n+1, 0);
        dp[0]= dp[1] = 1;
        for(int i=2; i<= n ; i++){
        for(int j=1 ; j<= i; j++){
            dp[i] += dp[j-1] * dp[i - j];
        }
        }
        return dp[n];
    }
    int numTrees(int n){
        return solve(n );
    }
};
//Catalon Number Solution 
// the answer for this solution is catalon number
class Solution {
    // Function to calculate factorial of n
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    // Function to calculate the nth Catalan number
    long long catalanNumber(int n) {
        long long numerator = factorial(2 * n);
        long long denominator = factorial(n + 1) * factorial(n);
        return numerator / denominator;
    }
    
public:
    int numTrees(int n) {
        return catalanNumber(n);
    }
};
