#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;
    int nodes, edges;
    bool directed;

    Graph(int n, int m, bool directed = true) {
        this->directed = directed;
        nodes = n;
        edges = m;
    }

    void insertNode(T u, T v) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (const auto& i : adjList) {
            cout << i.first << "-->";
            for (const auto& j : i.second) {
                cout << j << ' ';
            }
            cout << endl;
        }
    }

void DFSutil(T start , unordered_map<T , bool>& visited){
    cout << start << ' ';
    visited[start] = true;

    for(T next : adjList[start]){
        if(!visited[next]){
            DFSutil(next,visited);
        }
    }
}

  void DFS(T start){    
    unordered_map<T , bool> visited(nodes);
    DFSutil(start,visited);
  }
};
int main() {
    Graph<int> g(5, 5, false);
    g.insertNode(0, 1);
    g.insertNode(1,2);
    g.insertNode(1,4);
    g.insertNode(2,3);
    g.insertNode(3,4);

    g.printAdjList();
    g.DFS(0);
    return 0;
}
