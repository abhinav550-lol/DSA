#include <limits.h>
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> shortestPath(n+1 , 1e8);
    shortestPath[src] = 0;
    // run shortest path for n-1 times
    for(int i=1; i <= n ; i++){
        for(int j = 0 ; j <m ;j++){
            int u = edges[j][0];
            int v= edges[j][1];
            int wt = edges[j][2];
            if(shortestPath[v] > shortestPath[u] + wt){
                shortestPath[v] = shortestPath[u] + wt;
            }
        }
    }

    //negative cycle check
    bool flag = false;
        for(int j = 0 ; j <m ;j++){
            int u = edges[j][0];
            int v= edges[j][1];
            int wt = edges[j][2];
            if(shortestPath[v] > shortestPath[u] + wt){
                flag = true;
            }
        }
        if(flag) return {-1};
        return shortestPath;
    }
