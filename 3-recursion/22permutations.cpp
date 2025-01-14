#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 

 void solve(vector<int> nums, vector<vector<int>> &result,int index ){
    if(index>=nums.size()) {
        result.push_back(nums);
        return ;
    }

    for(int j=index;j<nums.size();j++){
        swap(nums[j],nums[index]);
        solve(nums,result,index+1);
        swap(nums[j],nums[index]);
    }

 } 

  vector<vector<int>> permutations(vector<int>& nums ){
    vector<vector<int>> result;
    int index = 0;
    solve(nums,result,index);
    return result;
  }

 void print_2d_vector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main(){
   vector<int> nums ={1,2,3};
   vector<vector<int>> result = permutations(nums);
   print_2d_vector(result);
  return 0;
}