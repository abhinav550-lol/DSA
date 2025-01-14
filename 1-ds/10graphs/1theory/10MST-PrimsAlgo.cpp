#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    unordered_map< int , list<pair<int ,int>>> adjList;
    for(int i = 0 ; i< m ;i++){
      int u = g[i].first.first;
      int v = g[i].first.second;
      int w = g[i].second;

      adjList[u].push_back(make_pair(v,w));
      adjList[v].push_back(make_pair(u,w));
    }    

    priority_queue<pair<int , pair<int ,int>> , vector<pair<int , pair<int ,int>> > , greater<pair<int , pair<int ,int>>>> pq;
    vector<int> inMST(n+1 , false);
    vector<pair<pair<int, int>, int>> MST;

    pq.push({0 , {1, -1}});
    while(!pq.empty()){
      auto curr = pq.top();
      pq.pop();

      int currNode = curr.second.first;
      int currParent = curr.second.second;
      int currWeight = curr.first;

      if(inMST[currNode] == 1){continue;}

      inMST[currNode] = 1;
      if(currParent != -1){
        MST.push_back({{currParent , currNode} , currWeight});
      }

      for(auto nextElem : adjList[currNode]){
        int nextNode = nextElem.first;
        int nextNodeWeight = nextElem.second;
        if(!inMST[nextNode]){
          pq.push({nextNodeWeight, {nextNode, currNode}});
        }
      }
    }
    return MST;
}

int main(){
   
  return 0;
}