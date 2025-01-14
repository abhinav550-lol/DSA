#include <unordered_map>
#include <list>
#include <iostream>
#include <map>
#include <queue>

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

    void BFS(T start) {
        map<T, bool> visited;
        queue<T> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
          T curr = q.front();
          q.pop();
          cout << curr << ' ';

        for(T nextElem : adjList[curr]){
          if(!visited[nextElem]){
            q.push(nextElem);
            visited[nextElem] = true;
          }
        }          
        }
    }
};
int main() {
    Graph<int> g(3, 3, false);
    g.insertNode(0, 1);
    g.insertNode(1,2);
    g.insertNode(2,0);
    g.printAdjList();
    g.BFS(0);
    return 0;
}
