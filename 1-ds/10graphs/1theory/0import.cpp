#include <iostream>
#include<bits/stdc++.h>
using namespace std;


 template< typename T>
class Graph{
    public:
    unordered_map<T , list<T>> adjList;
    int nodes , edges;
    bool directed;

    Graph(T n , T m,  bool directed = true){
        this -> directed = directed;
        nodes = n;
        edges = m;
    }

    void insertNode(T u , T v){
        adjList[u].push_back(v);
        if(!directed){
        adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adjList){
            cout << i.first <<"-->";
            for(auto j : i.second){
                cout<<j<<' ';
            }
            cout<<endl;
        }
    }
};