#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
 

class weightedGraph{
    public:
    unordered_map<int , list<pair<int ,int>>> adjList;
    int nodes, edges;
    bool undirected;

    weightedGraph(int n, int m, int u=false) :nodes(n), edges(m) , undirected(u){}

    void insertNode(int u,int v, int w){
        adjList[u].push_back(make_pair(v,w));
        if(undirected)
        adjList[v].push_back(make_pair(u, w));
    }
    void printGraph() {
        for (const auto& entry : adjList) {
            cout << "Node " << entry.first << ": ";
            for (const auto& neighbor : entry.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

};

int main(){
   int n, m;
   cout<<"Enter nodes and edges:"<<endl;
   cin>> n >> m;

   weightedGraph G(n,m);
   int u , v , w;
   for(int i=0; i<m; i++){
    cin >> u >> v >> w;
    G.insertNode(u , v , w);
   }

  return 0;
}