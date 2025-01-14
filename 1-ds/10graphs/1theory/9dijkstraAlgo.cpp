#include <iostream>
#include <vector>
#include <list>
#include <set>
#include<unordered_map>
#include<limits.h>
#include <queue>
using namespace std;

class customSettings{
    public:
    bool operator()(const pair<int ,int> a, const pair<int , int> b){
        return a.second > b.second;
    }
};


//Better Dijkstra's Algo Code In ./algo/graphs
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
    //By Set
    void shortestPaths(vector<int> &dist, int src){
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty()){
            auto curr = *st.begin();
            st.erase(st.begin());

            int currDistance = curr.first;
            int currNode = curr.second;

            for(auto nextElem : adjList[currNode]){
                int nextNode = nextElem.first;
                int nextNodeDistance = nextElem.second;
                if(dist[nextNode] > nextNodeDistance+currDistance){
                    //Entrie Removal
                    auto record = st.find(make_pair(dist[nextNode], nextNode ));
                    if(record != st.end()) st.erase(record);
                    //Updating Distance
                    dist[nextNode]=nextNodeDistance+currDistance;
                    st.insert(make_pair(dist[nextNode], nextNode));
                }   
            }
        }   
    }
    //By Heaps
    void shortestPathsHeaps(vector<int> &dist , int src){
          priority_queue<pair<int , int> , vector<pair<int ,int>> , customSettings> pq;
          pq.push(make_pair(src , 0));
          dist[src] = 0;
          while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currDistance = curr.second;
            int currNode = curr.first;
            for(auto nextElem : adjList[currNode]){
                int nextNode = nextElem.first;
                int nextNodeDistance = nextElem.second;
                if(dist[nextNode] > nextNodeDistance + currDistance){
                    dist[nextNode] = nextNodeDistance + currDistance;
                    pq.push(make_pair(nextNode,dist[nextNode]));
                }
            }
          }         
    }
};

int main()
{
    int n = 4;
    int m = 5;
    weightedGraph G(n, m, true);
    G.insertNode(0, 1, 5);
    G.insertNode(0, 2, 8);
    G.insertNode(1, 2, 9);
    G.insertNode(1, 3, 2);
    G.insertNode(2, 3, 6);

    int src = 0;
    vector<int> dist(n, INT_MAX);
    G.shortestPaths(dist, src);
    for (int i : dist)
    {
        cout << i << ' ';
    } cout << endl;
    G.shortestPathsHeaps(dist, src);
    for (int i : dist)
    {
        cout << i << ' ';
    }
    return 0;
}