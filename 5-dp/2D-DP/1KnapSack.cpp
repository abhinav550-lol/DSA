
//Recursion
#include <vector>
int solve(vector<int>&weight , vector<int> &value , int index , int W){
	if(index == 0){
		if(weight[0] <= W){
			return value[0];
		}else{
			return 0;
		}
	}
	int include(0) , exclude(0);
	if(weight[index] <= W){
		include =	value[index]+ solve(weight ,value , index-1, W-weight[index]);
	}
	exclude = solve(weight ,value , index-1, W);

	return max(include , exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value , n-1 , maxWeight);
}

//Memo
#include <vector>


int solve(vector<int>&weight , vector<int> &value , int index , int W,vector<vector<int>>& dp){
	if(index == 0){
		if(weight[0] <= W){
			return value[0];
		}else{
			return 0;
		}
	}
	if(dp[index][W] != -1){
		return dp[index][W];
	}
	int include(0) , exclude(0);
	if(weight[index] <= W){
		include =	value[index]+ solve(weight ,value , index-1, W-weight[index], dp);
	}
	exclude = solve(weight ,value , index-1, W, dp);

	dp[index][W] = max(include , exclude);
	return dp[index][W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n , vector<int>(maxWeight+1, -1));
	return solve(weight, value , n-1 , maxWeight, dp);
}
//Tabulation 
#include <vector>


int solve(vector<int>&weight , vector<int> &value , int index , int W){
	vector<vector<int>> dp(index , vector<int>(W+1, 0));
	
	for(int j=0; j <= W ; j++){ //Settings base case condition for all values of index =0 and maxCapacity of j from 0 till W
		if(weight[0] <=j){  
			dp[0][j] = value[0]; //If weight of index 0 is in bound of maxCapacity J (0 to W), then for 1 items, add the value
		}else{
			dp[0][j] = 0; //Add None
		}
	}	

	for(int i=1 ; i<index ; i++){ //Traverse from 2 Items till all items within bound of index or n
		for(int j= 0 ; j <=W; j++){ // Traverse from maxWeights that ranges from (0 To W)
			int include(0) , exclude(0);
			if(weight[i] <= j){
			include = value[i] + dp[i-1][j-weight[i]]; // Include Wali Cond
			}
			exclude = dp[i-1][j]; //Exclude Wali Cond
			dp[i][j] =max(include , exclude);  // dp[i][j] -> maxValue that can be attained for i(which is items ) and J(which is maxWeight)
		}
	}
	return dp[index-1][W]; // index -1 cuz we sent n as your input, 0 based index
	}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value , n , maxWeight);
}

//Space Optimization 
//1. 2 Arrays
int solve(vector<int>& weight, vector<int>& value, int index, int W) {
	vector<int> prev(W+1, 0);
	for(int w=0 ; w<=W; w++){
		if(weight[0] <= w){
			prev[w] = value[0];
		}else{
			prev[w] = 0;
		}
	}

	for(int i = 1 ; i < index ; i++){
	vector<int> curr(W+1 , 0);
		for(int j = 0; j <= W ; j++){
			int include(0) , exclude(0);
			if(weight[i] <= j){
				include = value[i] + prev[j-weight[i]];
			}
			exclude = prev[j];
			curr[j] = max(include , exclude);
		}
	prev= curr;
	}
	return prev[W];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value , n , maxWeight);
}

// 2. Space Optimzation ONLY 1 Array
#include <vector>

int solve(vector<int>& weight, vector<int>& value, int index, int W) {
	vector<int> curr(W+1, 0);
	for(int w=0 ; w<=W; w++){
		if(weight[0] <= w){
			curr[w] = value[0];
		}else{
			curr[w] = 0;
		}
	}

	for(int i = 1 ; i < index ; i++){
		for(int j = W; j >= 0 ; j--){
			int include(0) , exclude(0);
			if(weight[i] <= j){
				include = value[i] + curr[j-weight[i]];
			}
			exclude = curr[j];
			curr[j] = max(include , exclude);
		}
	}
	return curr[W];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value , n , maxWeight);
}