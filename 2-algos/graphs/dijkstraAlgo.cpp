#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;
    
    for(int i=0;i<vec.size();i++){
        pair<int,int> p = make_pair(vec[i][1],vec[i][2]);
        pair<int,int> p1 = make_pair(vec[i][0],vec[i][2]);
        adj[vec[i][0]].push_back(p);
        adj[vec[i][1]].push_back(p1);
    }
    
    set<pair<int,int>> s;
    
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i] = INT_MAX;
    }
    dist[source] =0 ;
    s.insert(make_pair(0,source));
    
    while(!s.empty()){
        
        pair<int , int> p = *(s.begin());
        s.erase(s.begin());
        int topNode = p.second;
        int topDistance = p.first;
        
        
        for(auto i:adj[topNode]){
            int v = i.first;
            int weight = i.second;
            if(dist[v] > dist[topNode] + weight){
                
            // delete firstly register entry    
            if(dist[v]!= INT_MAX){
                s.erase(s.find(make_pair(dist[v] , v)));
            }
                    dist[v] = dist[p.second] + weight;
                    s.insert(make_pair(dist[v],v)); 
        }
        
        }
        
    }
    
    return dist;
    
}