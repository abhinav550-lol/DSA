#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void allSubsets(vector<int> nums ,vector<vector<int>>& result,vector<int> subset,int index ){
    if(index>=nums.size()){
        result.push_back(subset);
        return ;
    }

    allSubsets(nums,result,subset,index+1);

    int currentElement = nums[index];
    subset.push_back(currentElement);
    allSubsets(nums,result,subset,index+1);
 }

 vector<vector<int>> powerSet(vector<int> nums){
    vector<vector<int>> result;
    vector<int> subset;
    int index = 0;
    allSubsets(nums,result,subset,index);
    return result;
 }

int main(){
   vector <int> nums = {1,2,3};
   vector<vector<int>> result = powerSet(nums);
      // Print the subsets
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
  return 0;
}