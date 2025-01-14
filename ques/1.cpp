// Given an integer, K. Generate all binary strings of size k without consecutive 1’s.

#include <iostream>
#include<vector>
using namespace std;

void solve(int k , string curr ,vector<string> & res){
    if(curr.length() == k){
        res.push_back(curr);
        return ;
    }

    if(curr.empty() || curr.back() == '0'){
        solve(k , curr + "0" , res);
        solve(k , curr + "1" , res);
    }

    if(curr.back() == '1'){
        solve(k , curr + "0" , res);
    }
}

vector<string> generateAllBinarySequences(int k){
    vector<string> res;
    solve(k , "" , res);
    return res;
}

int main() {
    int k ;
    cin >> k;
    vector<string> res = generateAllBinarySequences(k);
    for(auto s : res){
        cout << s << ' ';
    }cout << endl;
    return 0;
}