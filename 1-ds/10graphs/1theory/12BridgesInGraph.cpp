class Solution {
    int timer = 0;

    void DFS(int s, int parent, vector<int> &inTime, vector<int> &lowestInTime, vector<vector<int>> &bridges, vector<vector<int>> &adjList, vector<bool> &visited) {
        visited[s] = true;
        lowestInTime[s] = inTime[s] = timer++;
        
        for (auto nextElem : adjList[s]) {
            if (nextElem == parent) {
                continue;
            }
            if (!visited[nextElem]) {
                DFS(nextElem, s, inTime, lowestInTime, bridges, adjList, visited);
                lowestInTime[s] = min(lowestInTime[s], lowestInTime[nextElem]);
                
                if (inTime[s] < lowestInTime[nextElem]) {
                    bridges.push_back({s, nextElem});
                }
            } else {
                lowestInTime[s] = min(lowestInTime[s], inTime[nextElem]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> lowestInTime(n, -1);
        vector<int> inTime(n, -1);
        vector<bool> visited(n, false);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                DFS(i, -1, inTime, lowestInTime, bridges, adjList, visited);
            }
        }

        return bridges;
    }
};
