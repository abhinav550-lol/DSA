// Given a number n. Find the minimum number of perfect squares that sum up to n. 
// Note: A perfect square is an integer that is the square of another integer.

//Approach : 
/*
    Base cases:
    if(n == 0) then we already have a perfect square so "0"
    if(n < 0) then its a invalid answer so return the MAXIUM NO possible for calc of min squares, so that it fails
    Recursive Relation :
    if( for i=1 to n) i*i > n, then its definetly cant create a perfect square so, we search for valid squares.
    and if we find one, we add 1 to the result to include current squares.    
*/

//Memo
class Solution {
    int solve(int n, vector<int> &dp){
                if(n==0){
            return 0;
        }
        if(n<0 ){
            return INT_MAX;
        }
        if(dp[n] != INT_MAX){
            return dp[n];
        }
        for(int i=1 ;( i*i) <= n; i++){
            int res = solve(n - (i*i) ,dp);
            if(res!=INT_MAX){
                dp[n] = min(res + 1, dp[n]);
            }
        }
        return dp[n];
    }    
  public:
    int MinSquares(int n) {
        vector<int> dp(n+1 , INT_MAX);
        return solve(n ,dp);
    }
};
//Tabulation
class Solution {
    int solve(int n){
        vector<int> dp(n+1 , INT_MAX);
        dp[0] = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j*j <= i ; j++){
                dp[i] = min(1+dp[i - (j*j)] , dp[i]);
            }
        }
        return dp[n];
    }    
  public:
    int MinSquares(int n) {
        return solve(n);
    }
};
//Space Optimzation
