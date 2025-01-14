#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool isSafe(vector<vector<int>> &chessBoard, int row , int col , int n){
    int x = row;
    int y = col;

    while(x >= 0){
        if(chessBoard[x][y] == 1){
            return false;
        }//k
        x--;
    }

    x = row;
    y = col;
    while(x >= 0 && y >= 0){
        if(chessBoard[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y= col;
    while(x < n && y >= 0){
        if(chessBoard[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void placeQueens(vector<vector<int>> &chessBoard,vector<vector<int>> &res, int col , int n){
    if(col >= n){
        vector<int> ans;
        for(auto i : chessBoard){
            for(auto j : i) ans.push_back(j);
        }
        res.push_back(ans);
        return ;
    }

    for(int i=0; i<n;i++){
        if(isSafe(chessBoard, i , col , n)){
            chessBoard[i][col] = 1;
            placeQueens(chessBoard, res, col + 1, n);
            chessBoard[i][col] = 0;
        } 
     }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> chessBoard(n, vector<int>(n,0));
    vector<vector<int>> res;
    placeQueens(chessBoard, res, 0 , n);
    return res;
}

int main(){
   
  return 0;
}