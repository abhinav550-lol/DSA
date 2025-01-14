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

bool compareWeights(vector<int> &a , vector<int> &b){
    return a[2] <b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){
    DisjointSet D(n);
  sort(edges.begin() , edges.end(), compareWeights);
  int minWt = 0;

  for(int i=0 ; i<edges.size() ;i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    if(D.findParent(u) != D.findParent(v)){
        minWt += wt;
        D.unionSet(u , v);
    }
  }  
  return minWt;
}

int main(){
   DisjointSet d(5);

  return 0;
}
