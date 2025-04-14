#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
Bellman Ford, Single Sorced Shortest Path Algorithm 
-Helpful in detecting negative cycles

//Thought Process 
Run N-1 Iterations to obtain the shortest distances between src and all nodes. 
In each iteration, we want to iterate over all edges and check for the shortest distance updates

How to detect negative cycle?
Checking for a negative cycle, we run another iteration one last time to check if we can get another distance reduction between nodes, if we can there exists a negative cycle
*/


vector<int> bellmanFord(vector<vector<int>> &edges , int n , int src){
	vector<int> dist(n , INT_MAX);
	dist[src] =0;

	for(int i = 0 ; i < n - 1 ; i++){
		for(auto edge : edges){
			int u = edge[0] , v=  edge[1] , w = edge[2];
			if(dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
		}
	}
	
	for(auto edge : edges){
		int u = edge[0] , v=  edge[1] , w = edge[2];
		if(dist[u] + w < dist[v]) return {}; 
	}

	return dist;
}

int main() {
	vector<vector<int>> edges = {
    {0, 1, 1},
    {1, 2, -1},
    {2, 3, -1},
    {3, 1, -1} // This creates a negative cycle: 1 -> 2 -> 3 -> 1 with total weight -3
	};

	vector<int> res = bellmanFord(edges , 4 , 0);
	if(res.empty()){
		cout << "Negative Cycle Detected." << endl;
	}else{
		for(auto dist : res) cout << dist << ' ';
	}
	return 0;
}