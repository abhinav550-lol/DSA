#include <bits/stdc++.h>
void findParent(map<int , list<int>> adjList,int s ,int t, vector<int> &parent, map<int , bool> &visited){
    queue<int> q;
    visited[s]= true;
    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int nextElem : adjList[curr]){
            if(!visited[nextElem] && nextElem != parent[curr]){
                q.push(nextElem);
                visited[nextElem]= true;
                parent[nextElem] = curr;
            }
        }
    }
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    map<int , list<int>> adjList;
    for(int i=0; i<m; i++){
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }
    vector<int> parent(n+1, -1);
    map<int , bool> visited;
    findParent(adjList,s,t,parent,visited);

    vector<int> shortestPath;
    int currNode = t;
    shortestPath.push_back(t);
    while(currNode!=s){
        currNode = parent[currNode];
        shortestPath.push_back(currNode);
    }
    reverse(shortestPath.begin() , shortestPath.end());
    return shortestPath;
}