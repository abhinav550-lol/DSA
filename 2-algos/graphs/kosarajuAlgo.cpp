#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void topoSort(int curr, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &s){
    visited[curr] = 1;
    for(auto nextElem : adjList[curr]){
        if(!visited[nextElem]){
            topoSort(nextElem, adjList, visited, s);
        }
    }
    s.push(curr);
}

vector<vector<int>> transposeGraph(vector<vector<int>> &adjList){
    int v = adjList.size();
    vector<vector<int>> tGraph(v);
    for(int curr = 0; curr < v; curr++){
        for(auto nextElem : adjList[curr]){
            tGraph[nextElem].push_back(curr);
        }
    }
    return tGraph;
}

void dfs(int curr, vector<vector<int>> &tGraph, vector<int> &visited){
    visited[curr] = true;
    for(auto nextElem : tGraph[curr]){
        if(!visited[nextElem]){
            dfs(nextElem, tGraph, visited);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
    //adjlist
    vector<vector<int>> adjList(v);
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
    }
    //topological order
    vector<int> visited(v, 0);
    stack<int> s;
    for(int i = 0; i < v; ++i){
        if(!visited[i]){
            topoSort(i, adjList, visited, s);
        }
    }
    // transpose of graph
    vector<vector<int>> tGraph = transposeGraph(adjList);
    
    //traverse and count scc
    fill(visited.begin(), visited.end(), 0);
    int scc = 0;
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(!visited[curr]){
            scc++;
            dfs(curr, tGraph, visited);
        }
    }   
    return scc;
}

int main(){
   
  return 0;
}