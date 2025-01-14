#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    vector<int> nextSmallerElements(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1 ; i>=0 ;i--){
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
        vector<int> prevSmallerElements(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0 ; i<n;i++){
            int curr = arr[i];
            while(s.top()!=-1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevElements(n);
        vector<int> nextElements(n);
         prevElements = prevSmallerElements(heights, n);
         nextElements = nextSmallerElements(heights, n);
        int area = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            if(nextElements[i]==-1){
                nextElements[i] = n;
            }
            int width = nextElements[i] - prevElements[i] - 1;
            int currArea = width * height;
            area = max(currArea, area);
        }
        return area;
    }

int main(){
   vector<int> heights = {2,1,5,6,2,3};
   cout<<largestRectangleArea(heights);
     return 0;
}