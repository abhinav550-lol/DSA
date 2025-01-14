//recursion 
class Solution
{
    int solve(int n,int a[], int curr ,int prev, vector<vector<int>> &dp){
        if(curr >= n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int inc = 0;
        if(prev == -1 || a[prev] < a[curr]){
            inc = 1 + solve(n , a, curr+1, curr, dp);
        }
            
        int exc = solve(n , a , curr+1 , prev, dp);
        
            
        dp[curr][prev+1] = max(inc , exc);
        return dp[curr][prev+1] ;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
       return solve(n , a, 0 , -1, dp);
    }
};

//memoization 
class Solution
{
    int solve(int n,int a[], int curr ,int prev, vector<vector<int>> &dp){
        if(curr >= n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int inc = 0;
        if(prev == -1 || a[prev] < a[curr]){
            inc = 1 + solve(n , a, curr+1, curr, dp);
        }
            
        int exc = solve(n , a , curr+1 , prev, dp);
        
            
        dp[curr][prev+1] = max(inc , exc);
        return dp[curr][prev+1] ;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
       return solve(n , a, 0 , -1, dp);
    }
};

//Tabulation

class Solution
{
int solve(int n,int a[]){
    vector<vector<int>> dp(n+1 , vector<int>(n+1, 0));
    for(int curr = n - 1; curr >= 0 ; curr--){
        for(int prev = curr - 1; prev >= -1; prev--){
            int inc = 0;
            if(prev == -1 || a[prev] < a[curr]){
            inc  = 1 + dp[curr+1][curr+1];
            }
            int exc = dp[curr+1][prev+1];

            dp[curr][prev+1] = max(inc , exc);
        }
    }   
    return dp[0][0];
}
public:
//Function to find length of longest increasing subsequence.
int longestSubsequence(int n, int a[])
{
return solve(n , a);
}
};

//Space optimzation tc : o(n^2) sc :  o(n) , still fails
class Solution
{
int solve(int n,int a[]){
    vector<int> next(n+1, 0);
    for(int curr = n - 1; curr >= 0 ; curr--){
        vector<int> crr(n+1, 0);
        for(int prev = curr - 1; prev >= -1; prev--){
            int inc = 0;
            if(prev == -1 || a[prev] < a[curr]){
            inc  = 1 + next[curr+1];
            }
            int exc = next[prev+1];

            crr[prev+1] = max(inc , exc);
        }
        next = crr;
    }   
    return next[0];
}
public:
//Function to find length of longest increasing subsequence.
int longestSubsequence(int n, int a[])
{
return solve(n , a);
}
};

//DP with BINARY SEARCH

// watch the video from 30:00 to 39:00 Lec 119 for intution

class Solution
{
    public:
    int longestSubsequence(int n, int a[])  {
        if(n== 0) return 0;

        vector<int> elements;
        elements.push_back(a[0]);

        for(int i=1 ; i<n ; i++){
            if(a[i] > elements.back()){
                elements.push_back(a[i]);
            }else{
                int index = lower_bound(elements.begin() , elements.end() , a[i]) - elements.begin();
                elements[index] = a[i];
            }
        }
        return elements.size();
    }
};

