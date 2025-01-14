#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\10graphs\1theory\0import.cpp"


// we only start edges number from 1 to n, becuz questions required it

//Directed Graph Using DFS
bool DFS(int start , map<int , bool> &visited , map<int , bool> &path , map<int , list<int>> adjList){
  visited[start ] = true;
  path[start ] = true;
  for(int nextElem : adjList[start]){
    if(!visited[nextElem]){
      if (DFS(nextElem, visited, path, adjList)) {
        return true;
      }
    }else if(path[nextElem]){
      return true;
    }
  }
  path[start] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  map<int, list<int>> adjList;
  for(int i = 0 ; i<edges.size() ; i++){
    pair<int,int> curr = edges[i];
    adjList[curr.first].push_back(curr.second);
  }
  
  map<int , bool> visited;  
  map<int , bool> path;
  for(int i=1;i<=n;i++){
  if(!visited[i]){
    if(DFS(i , visited, path , adjList)) return true;
  }
  }
 return false;
}
//Cycle Detection using BFS 

vector<int> findIndegree(const vector<list<int>>& adjList, int n) {
    vector<int> indegree(n+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int nextElem : adjList[i]) {
            indegree[nextElem]++;
        }
    }
    return indegree;
}

bool hasCycle(const vector<list<int>>& adjList, int n, vector<int>& indegree) {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int visitedNodes = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        visitedNodes++;

        for(int nextElem : adjList[curr]) {
            indegree[nextElem]--;
            if(indegree[nextElem] == 0) {
                q.push(nextElem);
            }
        }
    }

    return visitedNodes != n; 
}

bool detectCycleInDirectedGraph(int n, const vector<pair<int, int>>& edges) {
    vector<list<int>> adjList(n+1);
    for(const auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
    }

    vector<int> indegree = findIndegree(adjList, n); 

    return hasCycle(adjList, n, indegree);
}


int main(){
    int n, m;
    Graph<int> G(n,m,true);
    cin >> n >> m;
    cout << "Insert Edges" <<endl;
    for(int i = 0 ; i<m ; i++){
        int u , v;
        cin >> u >> v;
        G.insertNode(u,v);
    }
    vector<int> v;
    // cycleDetection(G );
  return 0;
}