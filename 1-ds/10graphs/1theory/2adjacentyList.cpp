#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
map<int, list<int>> buildGraph(int nodes, int edges, multimap<int, int> edgeList) {
    map<int, list<int>> adjList;

    for (auto it = edgeList.begin(); it != edgeList.end(); ++it) {
        adjList[it->first].push_back(it->second);
    }

    return adjList;
}

void printList(const list<int>& l) {
    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }
}


int main(){
    int nodes = 3;  
    int edges = 3;  
    multimap<int, int> edgeList;
    
    edgeList.emplace(0, 1);
    edgeList.emplace(1, 2);
    edgeList.emplace(2, 0);

   map<int , list<int>> List = buildGraph(nodes, edges, edgeList);

    for(auto i : List){
        cout << i.first << "------>";
        printList(i.second);
    }
    // cout << pathExists(list, 0, 1);


  return 0;
}