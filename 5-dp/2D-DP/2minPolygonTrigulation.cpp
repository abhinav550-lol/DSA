/*
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.
*/

/*

Approach :
We know the first and the last index will always be adjacent to each other in a polygon.
ie : values = [1 , 2, 3 , 4];
then 1 and 4 will always be adjacent to each other.
lets call first index as i and last index as j
now, for every i and j, we can pick k from the rest of the values left. Suppose k = 2. 
now, compute the triangle formed by i j and k (i* j *k ) and compute solve(i , k) and solve(k , j);
so, we have succesfully divided this problem into 3 sub problems...
1 -> 2 -> 4 (first triangle)
1 -> 2 (second triangle which is invalid)
2 -> 3 -> 4 (third triange)

*/


//Recursion
class Solution {
    int solve(int i, int j, vector<int> &values) {
        if (i+1 == j) {
            return 0;  
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int result = (values[i] * values[j] * values[k]) +
                         solve(i, k, values) +
                         solve(k, j, values);
            ans = min(ans, result);
        }
        return ans;
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0; 
        return solve(0, n - 1, values);
    }
};

//Recursion + Memoization 
class Solution {
    int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp) {
        if (i+1 == j) {
            return 0;  
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int result = (values[i] * values[j] * values[k]) +
                         solve(i, k, values, dp) +
                         solve(k, j, values, dp);
            dp[i][j] = min(dp[i][j], result);
        }
        return dp[i][j];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0; 
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, n - 1, values, dp);
    }
};
//Tabulation
class Solution {
    int solve( vector<int> &values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=n-1 ; i>= 0; i--){ //Started from behind cuz wanted to compute the greater indexes/triangles first
            for(int j=i+2; j<n ; j++){ //i+2 ensures the i and j form a triangle as i == j means a point and i + 1 == j means a line, those are not a triangle
                    dp[i][j] = INT_MAX;
                for(int k=i+1; k<j;k++){
                    int result = (values[i]*values[j]*values[k]) + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], result);
                }
            }
        }
        return dp[0][n-1];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0; 
        return solve(values);
    }
};