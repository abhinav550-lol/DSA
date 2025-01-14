/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

/*
Approach:
base case: 
if we have exhausted both the patten and string, that means its a valid string pattern.
if we only exhausted the pattern but string remains, then pattern is not valid.
if we only exhausted the string but not the pattern, then there are two cases.
1) if the pattern has all remaining indices as *, then we can take those empty string and string will be valid. 
ie : s = aac  , p = *aac. when we come to the first index, then we can replace * with "" and it will be valid.
2) if the pattern has anything other than * then it is not valid. 
ie : s = aac , p= a*aac 

now , RR:
if the pattern current charecter is equal to the string current charecter or the pattern current charecter is equal to "?", then
the current index is valid. (we can replace ? with any charecter ) so , we move i and j by 1 index for futher checks.
if the pattern current charecter is equal to *, then 
we have 2 cases :
1) consider the * as empty space 
2) consider the current string index charecter s[i] with the *.
ie : *b is same as b as we can just replace * with ""

for first case, we can just move the j index by one as we are considering it as empty.
for second case, we will reduce the i index by one while keeping the j index same. so, that will mean that we have including the part of string, that was extra.
ie : s = baabc , p = b*bc.
last two indexes are correct, then when we come to p[j] = * and s[i] = a
we move the i index by one as if we are including *with a so *a == a,
then same for the next a, *a - --- > *aa  == aa
and when we encounter the * as empty, we will get the right answer.
*/


//Recursion
class Solution {
    bool solve(string s , string p ,int i , int j){
        if(i < 0 && j < 0){
            return true;
        }
        if(i >= 0 && j < 0){
            return false;
        }
        if(i < 0 && j >= 0){
            for(int k=0;k<=j;k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?'){
            return solve(s , p , i-1 , j -1);
        }else if(p[j] == '*'){
            return solve(s, p , i-1 , j) or solve(s , p , i , j-1);
        }else{
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        return solve(s , p , s.length()-1 , p.length() -1 );
    }
};

//Memo
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool solve(const string& s, const string& p, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (i >= 0 && j < 0) {
            return false;
        }
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; ++k) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool ans;
        if (s[i] == p[j] || p[j] == '?') {
            ans = solve(s, p, i - 1, j - 1, dp);
        } else if (p[j] == '*') {
            ans = solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
        } else {
            ans = false;
        }
        return dp[i][j] = ans;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s, p, s.length() - 1, p.length() - 1, dp);
    }
};
