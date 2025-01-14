#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

int min(int a ,int b){
    return a > b ? b : a;
}

int TIMER = 0;

void dfs(unordered_map<int , list<int >> &adjList, int curr , int parent , vector<bool> &visited, int lowInTime[], int inTime[], vector<bool> &AP){
    visited[curr] = true;
    lowInTime[curr] = inTime[curr] = TIMER;
    TIMER++;
    int child = 0;
  for(auto nextElem : adjList[curr]){
    if(parent == nextElem ) continue;
    if(!visited[nextElem]){
        dfs(adjList, nextElem , curr , visited , lowInTime, inTime, AP );
        child++;
        lowInTime[curr] = min(lowInTime[nextElem] , lowInTime[curr]);
        if(lowInTime[nextElem ] >= inTime[curr] &&parent!= -1){
            AP[curr] = true;
        }
    }else{
        lowInTime[curr] = min(lowInTime[nextElem] , lowInTime[curr]);
    }
  }
  if(child > 1 && parent == -1){
    AP[curr] = true;
  }
}
 
int main(){
   vector<pair<int ,int>> edges;
   edges.push_back({0 , 1});
   edges.push_back({0 , 3});
   edges.push_back({0 , 4});
   edges.push_back({1 , 2});
   edges.push_back({3, 4});
   int n=5, e = 5;
   unordered_map<int , list<int>> adjList;
   for(auto it : edges){
    int u = it.first;
    int v = it.second;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
   }
   int lowInTime[n]; 
   int inTime[n];
   vector<bool> AP(n, false);
   vector<bool> visited(n , false);

   for(int i=0 ; i< n ;i++){
    if(!visited[i]){
        dfs(adjList, i , -1, visited, lowInTime, inTime, AP);
    }
   }
    for(int i = 0; i<n ; i++){
        if(AP[i]){
            cout << i << ' ';
        } 
    }
  return 0;
}