/*
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.
*/


//Recursion 
long long solve(int faces ,int die, int target){
    if(die != 0 && target == 0 || target < 0 || die == 0 && target != 0){
        return 0;
    }
    if(die == 0 && target == 0){
        return 1;
    }
    long long ans = 0;
    
    for(int i=1 ; i<= faces ; i++){
        ans += solve(faces , die-1 , target-i);
    }
    return ans;
}

class Solution {
  public:
    long long noOfWays(int m, int n, int x) {
      return solve(m , n , x);
    }
};

//Memo
long long solve(int faces ,int die, int target,  vector<vector<long long >> &dp){
    if(die != 0 && target == 0 || target < 0 || die == 0 && target != 0){
        return 0;
    }
    if(die == 0 && target == 0){
        return 1;
    }
    if(dp[die][target] != -1){
        return dp[die][target];
    }
    long long ans = 0;
    
    for(int i=1 ; i<= faces ; i++){
        ans += solve(faces , die-1 , target-i, dp);
    }
    return dp[die][target] = ans;
}

class Solution {
  public:
    long long noOfWays(int m, int n, int x) {
        vector<vector<long long>> dp(n+1, vector<long long>(x+1, -1));
      return solve(m , n , x, dp);
    }
};

//Tabulation 
class Solution {
    long long solve(int faces , int die , int target){
        vector<vector<long long>> dp(die + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1; 
        
        for(int i=1 ; i <= die ; i++){
            for(int j = 1 ; j <=target; j++){
                long long  ans = 0;
                for(int k=1; k<=faces ; k++){
                    if(j-k >= 0)
                    ans += dp[i-1][j-k];
                }
                dp[i][j] = ans;
            }
        }
        return dp[die][target];
    }
  public:
    long long noOfWays(int m, int n, int x) {
        return solve(m ,n , x);
    }
};
//so 

class Solution {
    long long solve(int faces , int die , int target){
        vector<long long> prev(target+1, 0);
        prev[0] = 1;
        
        for(int i=1 ; i <= die ; i++){
        vector<long long> curr(target+1, 0);
            for(int j = 1 ; j <=target; j++){
                long long  ans = 0;
                for(int k=1; k<=faces ; k++){
                    if(j-k >= 0)
                    ans += prev[j-k];
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[target];
    }
  public:
    long long noOfWays(int m, int n, int x) {
        return solve(m ,n , x);
    }
};
