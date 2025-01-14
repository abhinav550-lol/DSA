/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.
*/

/*
Approach : 
    Greedy + DP
    just search for every possible route, if the lane and the next pos contains a obstacle . then , just change the lane.
    else , increase the position in the same lane. 

*/

//Memo + Recursion
class Solution {
    int solve(int lane, int pos , vector<int>&obstacles , int n, vector<vector<int>> &dp){
        if(pos >= n-1){
            return 0;
        }
        if(dp[lane][pos] != -1){
            return dp[lane][pos];
        }
        dp[lane][pos] = INT_MAX;
         if(obstacles[pos+1] == lane){
            for(int newLane=1 ; newLane <= 3; newLane++){
                if(newLane != lane && obstacles[pos] != newLane){
                     dp[lane][pos] = min(solve(newLane , pos , obstacles , n, dp) + 1, dp[lane][pos] );
                }   
            }
         }else{
             dp[lane][pos] =  solve(lane, pos+1, obstacles , n, dp);
         }
         return dp[lane][pos] ;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int lane = 2;
        int pos = 0;
        vector<vector<int>> dp(4 , vector<int>(n, -1));
        return solve(lane , pos , obstacles, n, dp);
     return 0;
    }
};
//Tabulation 
class Solution {
    int solve(vector<int> &obstacles){
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, 1e9)); // dp[lane][pos]

        // Initialize the final position
        dp[1][n - 1] = 0;
        dp[2][n - 1] = 0;
        dp[3][n - 1] = 0;

        for (int pos = n - 2; pos >= 0; pos--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[pos] != lane&&obstacles[pos + 1] != lane) {
                        dp[lane][pos] = dp[lane][pos + 1]; // Move forward 
                    } else {
                        int ans = 1e9;
                        for (int newLane = 1; newLane <= 3; newLane++) {
                            if (newLane != lane && obstacles[pos] != newLane) {
                                ans = min(dp[newLane][pos + 1] + 1, ans); // Jump to another lane //TJos ;ome os important that we use pos + 1 as there might exist some case where a currPos is yet to be computed. if, we access it we will get incorrect answer.
                            }
                        }
                        dp[lane][pos] = ans;
                    }
            }
        }

        // The result is the minimum number of jumps to reach the end starting from lane 2 at position 0
        return min({dp[2][0], dp[1][0] + 1, dp[3][0] + 1}); // We add 1 for lane 3 and 1 as our final destination is lane 2. so, a sidejump is required
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
    }
};

//Space Optimzation 

//We see we only depend on the sideJumps for the next positon in the lane and the curr values.
class Solution {
    int solve(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, 0);

        next[1] = 0; // for ref
        next[2] = 0;
        next[3] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[pos + 1] == lane) {
                    int ans = 1e9;
                    for (int newLane = 1; newLane <= 3; newLane++) {
                        if (newLane != lane && obstacles[pos] != newLane) {
                            ans = min(next[newLane] + 1, ans);
                        }
                    }
                    curr[lane] = ans;
                } else {
                    curr[lane] = next[lane];
                }
            }

            next = curr;
        }

        return min({next[2], next[1] + 1, next[3] + 1});
    }

public:
    int minSideJumps(vector<int>& obstacles) { return solve(obstacles); }
};