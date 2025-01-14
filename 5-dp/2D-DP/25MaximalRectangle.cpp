/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/


//Optimzied soln
class Solution {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size() , 0 );
        int ans = INT_MIN;
        for(int i=0 ; i<matrix.size();i++){
            for(int j=0 ; j < matrix[0].size();j++){
                if(matrix[i][j] == '1'){
                    histogram[j] += 1;
                }else{
                    histogram[j] = 0;
                }
            }
            int res = largestRectangleArea(histogram);
             ans = max(ans , res);
        }
        return ans;
    }
};