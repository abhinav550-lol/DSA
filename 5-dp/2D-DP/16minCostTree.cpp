/*
Question : 
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.
*/

/*
Appraoch:
Base Case: 
when find such sub-tree with only 1 node, thats a leaf node and we are excluding left node values in our minCost addition. so, we return 0.

Recursive Relation:
We use a map to store every max value in a range of arr. for every [{i , j}] where 0 <= i <= j < n.
In the recursive relation, we run a loop for every possible partition possible b/w start and end .
 ie : 
[6 , 4 , 2] -> [6] [4,2] 
            -> [6, 4] [2]
we dont run the loop for i == end, as end + 1 will be a invalid index.  

we find the max leaf node value in leftSubTree via map(start , i) and same with rightSubTree using map(i + 1, end)
and solve for further downTrees using recursion where solve(start , i) + solve(i+1 , end)
and we find the minCost between all the possible arrangements.
*/

//Recursion  O(n^3)
class Solution {
    int solve(vector<int> &arr , map<pair<int , int>, int> &maxValues, int start , int end){
        if(start == end){
            return 0; //You are at a leaf node
        }

        int minCost = INT_MAX;
        for(int i=start; i < end ; i++){
             minCost = min(minCost , maxValues[{start , i}] * maxValues[{i+1, end}] + solve(arr , maxValues,start , i) + solve(arr, maxValues, i+1, end));
        }
        return minCost;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int , int> , int > maxValues;
        int n = arr.size();

        //this map saves all the maximum values in a range.
        for(int i=0; i< arr.size() ; i++){
            maxValues[{i , i}] = arr[i]; 
            for(int j=i+1; j< arr.size(); j++){
                maxValues[{i , j}] = max(arr[j] , maxValues[{i , j-1}]);
            }
        }
        return solve(arr, maxValues, 0, n-1);
    }
};
//Memo
class Solution {
    int solve(vector<int> &arr , map<pair<int , int>, int> &maxValues, int start , int end, vector<vector<int>> &dp){
        if(start == end){
            return 0; //You are at a leaf node
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int minCost = INT_MAX;
        for(int i=start; i < end ; i++){
             minCost = min(minCost , maxValues[{start , i}] * maxValues[{i+1, end}] + solve(arr , maxValues,start , i, dp) + solve(arr, maxValues, i+1, end, dp));
        }
        return  dp[start][end] = minCost;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
        map<pair<int , int> , int > maxValues;

        //this map saves all the maximum values in a range.
        for(int i=0; i< arr.size() ; i++){
            maxValues[{i , i}] = arr[i]; 
            for(int j=i+1; j< arr.size(); j++){
                maxValues[{i , j}] = max(arr[j] , maxValues[{i , j-1}]);
            }
        }
        return solve(arr, maxValues, 0, n-1, dp);
    }
};
//Tabulation
class Solution {
    int solve(vector<int> &arr , map<pair<int , int>, int> &maxValues,int n){
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));

        for(int start = n-1 ; start >= 0 ; start -- ){
            for(int end = start + 1; end < n;end++){
                int minCost = INT_MAX;
                for(int i=start ; i < end ; i++){
                    minCost = min(minCost, maxValues[{start , i}] * maxValues[{i+1, end}] + dp[start][i] +dp[i+1][end]);
                }
                dp[start][end] = minCost;
            }
        }


        return dp[0][n-1];
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int , int> , int > maxValues;

        //this map saves all the maximum values in a range.
        for(int i=0; i< arr.size() ; i++){
            maxValues[{i , i}] = arr[i]; 
            for(int j=i+1; j< arr.size(); j++){
                maxValues[{i , j}] = max(arr[j] , maxValues[{i , j-1}]);
            }
        }
        return solve(arr, maxValues, n);
    }
};
