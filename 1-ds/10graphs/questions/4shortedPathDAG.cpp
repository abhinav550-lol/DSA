#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class weightedGraph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    int nodes, edges;
    bool undirected;

    weightedGraph(int n, int m, int u = false) : nodes(n), edges(m), undirected(u) {}

    void insertNode(int u, int v, int w)
    {
        adjList[u].push_back(make_pair(v, w));
        if (undirected)
            adjList[v].push_back(make_pair(u, w));
    }
    void printGraph()
    {
        for (const auto &entry : adjList)
        {
            cout << "Node " << entry.first << ": ";
            for (const auto &neighbor : entry.second)
            {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
    void topologicalSort(int i, stack<int> &s, unordered_map<int, bool> &visited){
        visited[i] = true;
        for(auto nextElem : adjList[i]){
            if(!visited[nextElem.first]){
                topologicalSort(nextElem.first, s, visited);
            }
        }
        s.push(i);
    }
    void findShortestDistAllNodes(int src , vector<int> &dist, stack<int> &order){
        while(!order.empty()){
            int curr = order.top();
            order.pop();

            if(dist[curr] != INT_MAX){
                for(auto nextElem : adjList[curr]){
                    if(dist[nextElem.first] >  dist[curr] + nextElem.second){
                        dist[nextElem.first] = dist[curr] + nextElem.second;
                    }
                }
            }
        }
    }
};

int main()
{
    int n, m;
    n = 6;
    m = 9;

    weightedGraph G(n, m);
    G.insertNode(0, 1, 5);
    G.insertNode(0, 2, 3);
    G.insertNode(1, 2, 2);
    G.insertNode(1, 3, 6);
    G.insertNode(2, 3, 7);
    G.insertNode(2, 4, 4);
    G.insertNode(2, 5, 2);
    G.insertNode(3, 4, -1);
    G.insertNode(4, 5, -2);
    G.printGraph();

    unordered_map<int, bool> visited;
    stack<int> TopoOrder;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            G.topologicalSort(i, TopoOrder, visited);
    }

    int src = 1;
    vector<int> dist(n , INT_MAX);
    dist[src] = 0;
    G.findShortestDistAllNodes(src , dist, TopoOrder);

    for(auto i : dist){
        cout << i << ' ';
    }
    return 0;
}