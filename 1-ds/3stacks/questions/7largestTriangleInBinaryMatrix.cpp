#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
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
    int maxArea(int M[MAX][MAX], int n, int m){
        vector<int> heights(m,0);
        int maxArea = 0;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            if(M[i][j]==0){
                heights[j] = 0;
            }else{
                heights[j] +=1;
            }
           }
          maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};

int main()
{

    int M[MAX][MAX];

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
    Solution obj;
    cout << obj.maxArea(M, n, m) << endl;
}
