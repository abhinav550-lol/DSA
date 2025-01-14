/*
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
*/


/*
APPROACH : 
 'Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.' <- this line is very cruicial
 it says that we need to guarnetee a win regardless of the actual input. so, we are preparing for the game such that if we are given some n, we can ensure that we have the least possible wrong guesses.

 we need to find the min no of money for guarntee win and if we guess wrong(X), we give the "WRONG guessed amount (X)" .
 so , we need to consider the min(currentAns ,i(considering current guess was wrong) +  worstCase from(fn(start , i-1 + fn(i+1. end))) );
 we take maximum of the worst case possible for current "i" and we get the minimum possible solution for i in 1-n.
*/

//Recursion 
class Solution {
    int solve(int start ,int end){
        if(start >= end){
            return 0;
        }

        int res = INT_MAX;
        for(int i=start; i<=end ; i ++){
            res = min(res , i+max(solve(start , i-1) , solve(i+1 , end)));
        }
        return res;
    }

public:
    int getMoneyAmount(int n) {
      return solve(1, n);
    }
};

//Memo
class Solution {
    int solve(int start ,int end, vector<vector<int>> &dp){
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int res = INT_MAX;
        for(int i=start; i<=end ; i ++){
            res = min(res , i+max(solve(start , i-1, dp) , solve(i+1 , end, dp)));
        }
        return dp[start][end] = res;
    }

public:
    int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
      return solve(1, n, dp);
    }
};

//Tabulation 
class Solution {
    int solve(int n){
      vector<vector<int>> dp(n+2 , vector<int> (n+1 , 0 ));
      for(int start = n; start >= 1; start -- ){
        for(int end = start; end <= n; end++){
            if(start == end) continue;
            else{
        int res = INT_MAX;
        for(int i=start; i<=end ; i ++){
            res = min(res , i+max(dp[start][i-1] , dp[i+1][end]));
        }
         dp[start][end] = res;
            }
        }
      }
    return dp[1][n];
    }

public:
    int getMoneyAmount(int n) {
      return solve(n);
    }
};
