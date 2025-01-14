#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Directed Graph
vector<vector<int>> buildGraph(int n, int m, multimap<int, int> edgeList) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (multimap<int, int>::iterator i = edgeList.begin(); i != edgeList.end(); ++i) {
        matrix[i->first][i->second] = 1;
        //for undirected graph
        //matrix[i->second][i->first] = 1
    }

    return matrix;
}

bool pathExists(vector<vector<int>> matrix ,int a, int b){
    if(matrix[a][b] == 1){
        return true;
    }
 return false;
}

int main() {
    int nodes = 3;  
    int edges = 3;  
    multimap<int, int> edgeList;
    
    edgeList.emplace(0, 1);
    edgeList.emplace(1, 2);
    edgeList.emplace(2, 0);

    vector<vector<int>> matrix = buildGraph(nodes, edges, edgeList);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }

    cout << pathExists(matrix, 0, 1);

    return 0;
}