void DFS(int start, unordered_map<int, list<int>>& adjList, vector<bool>& visited, stack<int> &s) {
    visited[start] = true;
    for (int nextElem : adjList[start]) {
        if (!visited[nextElem]) {
            DFS(nextElem, adjList, visited, s);
        }
    }
        s.push(start);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    vector<int> tpOrder;
    vector<bool> visited(v);
    stack<int> s;
    
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            DFS(i, adjList, visited, s);
        }
    }
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        tpOrder.push_back(curr);
    }

    return tpOrder;
}