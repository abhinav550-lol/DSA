#include "C:\Users\Abhinav\Desktop\VS Code Projects\C C++ DSA\3.DSA in C++ Advanced\1-ds\10graphs\1theory\0import.cpp"
 //For Undirected Graph - Using BFS
// bool isCyclicBFS(int start, map<int, bool>& visited, map<int, list<int>>& adjList, map<int, int>& parent) {
//     queue<int> q;
//     q.push(start);
//     visited[start] = true;
//     parent[start] = -1;

//     while(!q.empty()) {
//         int curr = q.front();
//         q.pop();

//         for(int nextElem : adjList[curr]) {
//             if(!visited[nextElem]) {
//                 q.push(nextElem);
//                 visited[nextElem] = true;
//                 parent[nextElem] = curr;
//             } else if(nextElem != parent[curr]) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     map<int , list<int>> adjList;

//    for(int i = 0 ; i < m ; ++i){
//        int u = edges[i][0];
//        int v = edges[i][1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//    }

//     map<int , bool> visited;
//     map<int , int> parent;
//    for(int i = 0 ; i<n ; i++){
//        if(!visited[i]){
//            bool ans = isCyclicBFS(i , visited, adjList, parent);
//            if(ans == true){
//                return "Yes";
//            }
//        }
//    }
//    return "No";
// }
//For Undirected Graph - Using DFS
bool isCyclicDFS(int start,int parent , map<int , list<int>> adjList, map<int , bool> &visited){
  visited[start] = true;
  for(int nextElem : adjList[start]){
    if(!visited[nextElem]){
    if(isCyclicDFS(nextElem, start, adjList, visited)){
            return true;
        }
    }else if(nextElem != parent){
      return true;
    }

  }
  return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
  map<int , list<int>> adjList;
  for(int i=0;i<m;i++){
    int u = edges[i][0];
    int v = edges[i][1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  map<int , bool>visited;
  for(int i=0; i<n ; i++){
  if(!visited[i]){
    bool ans = isCyclicDFS(i,-1,adjList,visited);
    if(ans == true){
      return "Yes";
    }
    }
  }
  return "No";
}



int main(){
    int n, m;
    Graph<int> G(n,m,false);
    cin >> n >> m;
    cout << "Insert Edges" <<endl;
    for(int i = 0 ; i<m ; i++){
        int u , v;
        cin >> u >> v;
        G.insertNode(u,v);
    }
    // cycleDetection(G );
  return 0;
}