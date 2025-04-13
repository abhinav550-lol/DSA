//Floydd Warshal used to find the shortest path among all pairs of nodes. Multisource unlike dijsktra's
//Detects Negative Cycles

/*
This is basically a brute force algorithm which calc min cost among all the nodes via a node
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyddWarshal(vector<vector<int>> &adjMatrix , int n){
	vector<vector<int>> dist = adjMatrix;
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i <n ;  i++){
			for(int j = 0 ; j < n ; j++) dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
		}
	}
	return dist;
}
//how to detect negative cycle? 
// a negative cycle would cause a dist[i][i] value to be negative and we know, the distance between a node itself cant be negative
int main() {
	// Your code here
	return 0;
}