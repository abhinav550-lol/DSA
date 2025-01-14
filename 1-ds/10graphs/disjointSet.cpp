// disjoint set -> union , findParent       --------- Intially sare nodes are parent of them self
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    int n;

    DisjointSet(int nodes):n(nodes){
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int s){
        if(parent[s] == s){
            return s;
        }
        parent[s] = findParent(parent[s]); //Path Compression
        return parent[s];
    }
    void unionSet(int x , int y){
        int u = findParent(x);
        int v = findParent(y);
        if(rank[v] > rank[u]){
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++; // Rank
        }
    }
};


int main(){
   DisjointSet d(5);

  return 0;
}
