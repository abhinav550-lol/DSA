#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& nums, int k) {
        vector <int> temp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
           int j=(i+k)%nums.size();
            temp[j]=nums[i];
        }
        nums=temp;

    }

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    rotateArray(v, 1);
    for (int i : v)
    {
        cout << v[i] << ' ';
    }
    return 0;
}