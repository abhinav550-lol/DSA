#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
vector<int> findIndegree(unordered_map<int , list<int>> adjList, int v , int e){
    vector<int> in(v,0);
    for(int i = 0 ; i<v ; i++){
        for(int nextElem : adjList[i]){
            in[nextElem]++;
        }
    }
    return in;
}

void BFS( unordered_map<int , list<int>> &adjList ,vector<int> &indegree, vector<int> &res){
    queue<int> q;
    for(int i = 0; i < indegree.size() ; i++ ){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for(int nextElem : adjList[curr]){
            indegree[nextElem]--;
            if(indegree[nextElem] == 0){
                q.push(nextElem);
            }
        }
    }

}

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    vector<int> indegree = findIndegree(adjList, v, e);

    vector<int> res;
    BFS(adjList, indegree,res);

    return res;
}

int main(){
   
  return 0;
}