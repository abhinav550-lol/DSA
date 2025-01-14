/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/

/*
Approach :

we dont need to solve the question actually, we just need to imitate the operatorion while adding 1 if we do any. so we break it down into 2 parts :

base cases:
if word1 is smaller than word2, then we just need to insert the words that are remaining and those will be all 1 operation * word2 remaining indices.
if word2 is smaller than word2 , then we just need to delete the words that are remaining in word1,and those are all 1 operations * word1 remaining indices.

RR:
if the word1[i] === word2[j] , then no need to do any insertion deletion or replacement, simply move both forward

if the word1[i] != word2[j], then
we can recieve our answer via three ways, either we insert the charecter or delete a charecter or we replace a charecter from any charecter ahead of the stirng.

for insertion,
eg:  word1 = or , word2 = hor , i = 0 , j = 0
word1[i] = 'o';
word2[j] = 'h';
this can be resolved by inserting h in beginning of word1

so, 
 word1 = hor
 word2 = hor
 now, we need to analyze where our indices will move according to the words.
 for i, we have just inserting a missing charecter so our length is increased by 1 so we dont need to move i.
 for j, we will have to increase it as we have inserted the charecter that was required. (i , j+1)

for deletion,
eg: 
word1 = hjor , word2 = hor , i = 1 , j = 1
so, we have a  extra letter 'j' , if we delete it .
we dont know whether the next letter will satisfy the similar string condition 
thats why we only increase i , while keeping j same. (i+1 , j)

for replacement,
eg:
word1 = roh , word2 = hor , i = 0 , j = 0
to convert word1 to word2, we can simply repalce h and r.
so, we do that word1 = hor , word2 = hor, now we have proccessed the zeroth index for both.
now, we move both ahead to make the strings same. (i+1 , j+1)
*/

//Recursion

class Solution {
    int solve(string & word1 , string & word2 , int i , int j){
        if(i >= word1.length()){
            return word2.length() - j;
        }
        if(j >= word2.length()){
            return word1.length() - i;
        }

        if(word1[i] == word2[j]){
           return  solve(word1 , word2 , i+1 , j+1 );
        }else{
            int insertAns = 1 + solve(word1 , word2 , i , j+1);

            int deleteAns = 1 + solve(word1 , word2 , i+1 , j);

            int replaceAns = 1 + solve(word1, word2 , i+1 , j+1);

            return min(insertAns , min(deleteAns , replaceAns));
        }
    }

public:
    int minDistance(string word1, string word2) {
        return solve(word1 , word2 , 0 , 0);
    }
};

// Memo
class Solution {
    int solve(string & word1 , string & word2 , int i , int j, vector<vector<int>> &dp){
        if(i >= word1.length()){
            return word2.length() - j;
        }
        if(j >= word2.length()){
            return word1.length() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
           return dp[i][j] =  solve(word1 , word2 , i+1 , j+1 , dp);
        }else{
            int insertAns = 1 + solve(word1 , word2 , i , j+1, dp);

            int deleteAns = 1 + solve(word1 , word2 , i+1 , j, dp);

            int replaceAns = 1 + solve(word1, word2 , i+1 , j+1, dp);

            return dp[i][j] = min(insertAns , min(deleteAns , replaceAns));
        }
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        return solve(word1 , word2 , 0 , 0, dp);
    }
};

//Tabulation 
class Solution {
    int solve(string& word1, string& word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=0; i<=n ; i++){
            dp[i][m] = n - i;
        }
        for(int j=0; j<=m ; j++){
            dp[n][j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int insertAns = 1 + dp[i][j + 1];

                    int deleteAns = 1 + dp[i+1][j];

                    int replaceAns = 1 + dp[i + 1][j + 1];

                    dp[i][j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }
        }
        return dp[0][0];
    }

public:
    int minDistance(string word1, string word2) { return solve(word1, word2); }
};
//SO
class Solution {
    int solve(string& word1, string& word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        // Initialize the last row of the DP table
        for (int j = 0; j <= m; ++j) {
            next[j] = m - j;
        }

        for (int i = n - 1; i >= 0; --i) {
            curr[m] = n - i;
            for (int j = m - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    curr[j] = next[j + 1];
                } else {
                    int insertAns = 1 + curr[j + 1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j + 1];
                    curr[j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }
            next = curr;
        }
        return next[0];
    }

public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) {
            return word2.length();
        }
        if (word2.length() == 0) {
            return word1.length();
        }
        return solve(word1, word2);
    }
};
