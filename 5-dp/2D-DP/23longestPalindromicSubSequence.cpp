/*
Compare the longest common substring b/w the reversed and normal string, that is our largest palindromic sub sequence

*/

class Solution {
    string reverseString(string &s){
        string res = "";
        int j = s.length() - 1;
        while(j >= 0){
            res.push_back(s[j--]);
        }
        return res;
    }
        int solve(string text1 , string text2, int n , int m){
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int i=n-1; i >= 0 ; i--){
        for(int j= m-1 ; j >= 0 ; j--){
        int res = 0;
        if(text1[i] == text2[j]){
            res = 1 +next[j+1];
        }else{
            res = max(next[j] ,curr[j+1]);
        }
         curr[j] = res;
        }
        next = curr;
    }
    return next[0];
    }
      int lcs(string text1, string text2) {

    return solve(text1 , text2, text1.length() , text2.length());        
    }

public:
    int longestPalindromeSubseq(string s) {
        string reversed = reverseString(s);
        return lcs(s, reversed);
    }
};