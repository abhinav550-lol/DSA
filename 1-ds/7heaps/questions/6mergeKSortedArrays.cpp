#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class info{
    public :
    int data,row , col;
    info(int d, int i, int j){
        data = d;
        row = i;
        col = j;
    }
};

class customOptions{
    public:
    bool operator()(info* a ,info* b){
        return a -> data > b -> data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<info* , vector<info*> , customOptions> pq;
    vector<int> res;

    for(int i = 0; i<k ; i++){
        info* firstElems = new info(kArrays[i][0], i , 0);
        pq.push(firstElems);
    }

    while(!pq.empty()){
        info* curr = pq.top();
        pq.pop();
        
        res.push_back(curr -> data);

        int i = curr -> row;
        int j = curr -> col;
        if( j + 1 < kArrays[i].size()){
            info* next = new info(kArrays[i][j+1] , i , j + 1);
            pq.push(next);
        }
    }
    return res;
}


int main(){
   
  return 0;
}