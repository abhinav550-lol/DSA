#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void searchForPaths(vector<vector<int>> &arr, vector<string>& allPaths, string currentPath, int x, int y, vector<vector<bool>>& visited, int n) {
    if(x == n-1 && y == n-1) {
        allPaths.push_back(currentPath);
        return;
    }
        
    visited[x][y] = true;

    if(x < n-1 && arr[x+1][y] == 1 && !visited[x+1][y]) {
        searchForPaths(arr, allPaths, currentPath + 'D', x+1, y, visited, n);
    }
    if(y > 0 && arr[x][y-1] == 1 && !visited[x][y-1]) {
        searchForPaths(arr, allPaths, currentPath + 'L', x, y-1, visited, n);
    }
    if(y < n-1 && arr[x][y+1] == 1 && !visited[x][y+1]) {
        searchForPaths(arr, allPaths, currentPath + 'R', x, y+1, visited, n);
    }
    if(x > 0 && arr[x-1][y] == 1 && !visited[x-1][y]) {
        searchForPaths(arr, allPaths, currentPath + 'U', x-1, y, visited, n);
    }
    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> allPaths;
    string currentPath;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    if(arr[0][0] == 1) { 
        searchForPaths(arr, allPaths, currentPath, 0, 0, visited, n);
    }
    return allPaths;
}



int main(){
    vector<vector<int>> maze;
    int n = 4;
    for(int i =0 ; i < n ; i++ ){
        for(int j=0 ; j < n ; j++ ){
            cout << "Enter for " << i <<  "row"<< "and" << j << 'col' << endl; 
            int k;
            cin >> k;
            maze[i][j] = k;
        }
    }

    vector<string> res = searchMaze(maze, n);
    for(auto s : res){
        cout << s << endl;
    }
    return 0;
}
