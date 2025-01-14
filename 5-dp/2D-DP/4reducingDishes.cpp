/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

*/

/*
Approach :
It is based on the same pattern as knap sack. include and exclude game
*/

//Recursion 
class Solution {
    int solve(int curr,vector<int> &satisfaction , int n, int time){
        if(curr >= n){
            return 0;
        }

        time++;
        int include =( time * satisfaction[curr] )+  solve(curr+1, satisfaction , n , time) ;
        int exclude = solve(curr+1 , satisfaction , n , time - 1);

        return max(include , exclude );
    }   

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        //we sort to ensure that we get the greater likeable dishes for multiplication with greater time value.
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();
        return solve(0 ,satisfaction ,n , 0);
    }
};

//Memoization 
class Solution {
    int solve(int curr,vector<int> &satisfaction , int n, int time,  vector<vector<int>> &dp){
        if(curr >= n){
            return 0;
        }
        if(dp[curr][time] != -1){
            return dp[curr][time];
        }

        int include =( (time + 1 )* satisfaction[curr]) +  solve(curr+1, satisfaction , n , time + 1, dp) ;
        int exclude = solve(curr+1 , satisfaction , n , time , dp);

        dp[curr][time] = max(include , exclude );
        return dp[curr][time];
    }   

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n+1 , -1));
        int res = solve(0 ,satisfaction ,n , 0, dp);
        return res ;
    }
};
// Tabulation 
class Solution {
    int solve(vector<int> &satisfaction , int n){
          vector<vector<int>> dp(n+1, vector<int>(n+1 , 0));
          for(int i=n-1; i >= 0 ; i--){
           for(int j=i; j >= 0 ; j--){
           int include = ((j + 1) * satisfaction[i]) + dp[i + 1][j + 1];
            int exclude = dp[i+1][j];
            dp[i][j] = max(include , exclude);
           }
          }       
          return dp[0][0]; // for first dish and 0 time taken
    }   

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();
        int res = solve(satisfaction ,n);
        return res ;
    }
};
//Space optimzation 
class Solution {
    int solve(vector<int> &satisfaction , int n){
          vector<int> next(n+1, 0);
          for(int i=n-1; i >= 0 ; i--){
          vector<int> curr(n+1, 0);
           for(int j=i; j >= 0 ; j--){
           int include = ((j + 1) * satisfaction[i]) +next[j+1];
            int exclude = next[j];
           curr[j] = max(include , exclude);
           }
           next = curr;
          }       
          return next[0]; // for first dish and 0 time taken
    }   

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();
        int res = solve(satisfaction ,n);
        return res ;
    }
};