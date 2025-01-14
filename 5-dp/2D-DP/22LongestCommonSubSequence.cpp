//reucursion
class Solution {
    int solve(string text1 , string text2 , int i , int j, vector<vector<int>> &dp){
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int res = 0;
        if(text1[i] == text2[j]){
            res = 1 + solve(text1, text2 , i+1 , j+1, dp);
        }else{
            res = max(solve(text1 , text2 , i+1 , j, dp) , solve(text1, text2 , i , j+1, dp));
        }
        return dp[i][j] = res;
    }

public:
  int longestCommonSubsequence(string text1, string text2) {

    int i = 0;
    int j =0;
    vector<vector<int>> dp(text1.length() + 1 , vector<int> (text2.length() + 1 , -1));
    return solve(text1 , text2 , i , j, dp);        
    }
};

//Memo
class Solution {
    int solve(string text1 , string text2 , int i , int j, vector<vector<int>> &dp){
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int res = 0;
        if(text1[i] == text2[j]){
            res = 1 + solve(text1, text2 , i+1 , j+1, dp);
        }else{
            res = max(solve(text1 , text2 , i+1 , j, dp) , solve(text1, text2 , i , j+1, dp));
        }
        return dp[i][j] = res;
    }

public:
  int longestCommonSubsequence(string text1, string text2) {

    int i = 0;
    int j =0;
    vector<vector<int>> dp(text1.length() + 1 , vector<int> (text2.length() + 1 , -1));
    return solve(text1 , text2 , i , j, dp);        
    }
};
//Tab
class Solution {
    int solve(string text1 , string text2, int n , int m){
    vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));
    for(int i=n-1; i >= 0 ; i--){
        for(int j= m-1 ; j >= 0 ; j--){
        int res = 0;
        if(text1[i] == text2[j]){
            res = 1 + dp[i+1][j+1];
        }else{
            res = max(dp[i+1][j] ,dp[i][j+1]);
        }
         dp[i][j] = res;
        }
    }
    return dp[0][0];
    }

public:
  int longestCommonSubsequence(string text1, string text2) {

    return solve(text1 , text2, text1.length() , text2.length());        
    }
};
//Space Optimzation 
class Solution {
    int solve(string text1 , string text2, int n , int m){
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int i=n-1; i >= 0 ; i--){
        for(int j= m-1 ; j >= 0 ; j--){
        int res = 0;
        if(text1[i] == text2[j]){
            res = 1 +next[j+1];
        }else{
            res = max(next[j] ,curr[j+1]);
        }
         curr[j] = res;
        }
        next = curr;
    }
    return next[0];
    }

public:
  int longestCommonSubsequence(string text1, string text2) {

    return solve(text1 , text2, text1.length() , text2.length());        
    }
};
