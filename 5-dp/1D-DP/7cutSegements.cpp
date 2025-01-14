/*
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.
*/

#include <bits/stdc++.h>

// Recursion
int solve(vector<int> lengths, int n){
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return -1;
	}
	int ans = -1;
	for(int i = 0 ; i < lengths.size(); i ++){
		int maxSegements = solve(lengths , n-lengths[i]);
		if(maxSegements != -1){
			ans = max(maxSegements+1, ans) ;
		}
	}
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> lengths = {x ,y, z};
	int maxSegements = solve(lengths , n);
	return maxSegements < 0 ? 0 : maxSegements;
}

//Memoization 

int solve(vector<int> lengths , vector<int> &dp , int n){
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return INT_MIN;
	}
	if(dp[n] != INT_MIN){
		return dp[n];
	}
	for(int i=0 ; i<lengths.size() ; i++){
		int maxSegements = solve(lengths, dp , n-lengths[i]);
		if(maxSegements != INT_MIN){
			dp[n] = max(dp[n], maxSegements+1);
		}
	}
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> lengths = {x ,y, z};
	vector<int> dp(n+1 , INT_MIN);
	int maxSegements = solve(lengths ,dp , n);
	return maxSegements ==INT_MIN ? 0 : maxSegements;	
}

//Tabulation 
int solve(vector<int> lengths , vector<int> &dp , int n){
	dp[0] = 0;
	for(int i =1 ; i <= n ; i++){
		for(int j = 0 ; j < lengths.size() ; j++){
			if(dp[i - lengths[j]] != INT_MIN && i - lengths[j] >= 0){
				dp[i] = max(dp[i-lengths[j]]+1 , dp[i]);
			}
		}
	}
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	vector<int> lengths = {x ,y, z};
	vector<int> dp(n+1 , INT_MIN);
	int maxSegements = solve(lengths ,dp , n);
	return maxSegements ==INT_MIN ? 0 : maxSegements;
}

// no space optimization possible 

