#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> m, int n, vector<vector<int>> visited, int newx, int newy)
{
    if ((0 <= newx && newx < n) && (0 <= newy && newy < n) && visited[newx][newy] == 0 && m[newx][newy] == 1)
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> m, vector<string> &res, string path, vector<vector<int>> visited, int x, int y, int n)
{
    if (x == n - 1 &&y == n - 1)
    {
        res.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(m, n, visited, newx, newy))
    {
        path.push_back('D');
       solve(m, res, path, visited, newx, newy, n);
        path.pop_back();
    }
    // UP
    newx = x - 1;
    newy = y;
    if (isSafe(m, n, visited, newx, newy))
    {
        path.push_back('U');
      solve(m, res, path, visited, newx, newy, n);
        path.pop_back();
    }

    newx = x;
    newy = y - 1;
    if (isSafe(m, n, visited, newx, newy))
    {
        path.push_back('L');
            solve(m, res, path, visited, newx, newy, n);
        path.pop_back();
    }

    newx = x;
    newy = y + 1;
    if (isSafe(m, n, visited, newx, newy))
    {
        path.push_back('R');
            solve(m, res, path, visited, newx, newy, n);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> ratMaze(vector<vector<int>> m, int n)
{
    vector<string> res;
    string path = " ";
    int strx(0), stry(0);

    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    solve(m, res, path, visited, strx, stry, n);
    return res;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = ratMaze(m, 4);
    for (string s : result)
    {
        cout << s << ' ';
    }
}