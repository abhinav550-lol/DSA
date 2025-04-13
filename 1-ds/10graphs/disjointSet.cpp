#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU{
	vector<int> rank;
	vector<int> parent;
	vector<int> size;
	int n;
	
	public:
	DSU(int c) : n(c){
		for(int i = 0 ; i < c ; i++){
			rank.push_back(0);
			size.push_back(1);
			parent.push_back(i);
		}
	}

	void unionByRank(int u , int v){
		int parentU = findParent(u);
		int parentV = findParent(v);
		if(parentU == parentV) return ;
		else{
			if(rank[parentU] > rank[parentV]){
				parent[parentV] = parentU;
			}else{
				if(rank[parentU] == rank[parentV]) rank[parentV]++;
				parent[parentU] = parentV;
			}
		}
	}

	void unionBySize(int u , int v){
		int parentU = findParent(u);
		int parentV = findParent(v);
		if(parentU == parentV) return ;
		else{
			if(size[parentU] > size[parentV]){
				size[parentU] += (size[parentV]);
				parent[parentV] = parentU;
			}else{
				size[parentV] += (size[parentU]);
				parent[parentU] = parentV;
			}
		}
	}
	
	int findParent(int u){
		if(parent[u] != u){
			parent[u] = findParent(parent[u]);
		}
		return parent[u];
	}

};


int main() {
	// Your code here
	DSU ds(5);
	vector<pair<int , int>> edges = {{0 , 1} , {1 , 2} , {3 , 4} , {2 , 3}};
	for(pair<int , int> edge : edges){
		ds.unionByRank(edge.first , edge.second);
		//check if 2 and 3 are in same component
		if(ds.findParent(2) == ds.findParent(3)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}

	DSU ds2(5);
	for(pair<int , int> edge : edges){
		ds2.unionBySize(edge.first , edge.second);
		//check if 2 and 3 are in same component
		if(ds2.findParent(2) == ds2.findParent(3)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}