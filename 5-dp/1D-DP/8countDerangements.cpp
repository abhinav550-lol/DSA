/*
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
*/

/*Appraoch 
Base cases : 
if(only 1 element) , then no derangements possible.
if(only 2 elements), then 1 derangements possible.

recursive relation :
there only 1 possible a element cant be present for it to be a derangements, thats is the index itself.
ie : if [0 ,1 , 2, 3] then 0 cant be at 0 index for it be a arragements.
then, you can multiple it with the sum problems (countDerangements(n-1) + countDerangements(n-2)) as,
there only 2 possiblities for the index of the element instead of which will be replaced for.
suppose 0 is placed at ith element index. then, "i" can go at two places:
at 0 or any other index other than 0 and i itself 
(n-1) and (n-2)
*/

// Recursion 
long long int countDerangements(int n) {
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    int derangements = (n-1) *( countDerangements(n-1) + countDerangements(n-2));

    return derangements; 
}

//Memo
#define MOD 1000000007
#include <vector>
long long int solve(int n, vector<long long int>& dp){
    if(n== 1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n] != -1 ){
        return dp[n];
    }

    dp[n] =( ((n-1)%MOD) *((solve(n-1, dp )%MOD) + (solve(n-2, dp)%MOD))) %MOD;
    return dp[n];  
}

long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    long long int res = solve(n , dp);
    return res;
}

//Tabulation
#include <vector>
#define MOD 1000000007

long long int solve(int n){
    // intial case of 3
    long long int minusTwoDerangements = 0;
    long long int minusOneDerangements = 1;
    for(int i=3 ; i<= n; i++){
        long long int curr = (((i-1)%MOD) * ((minusOneDerangements)%MOD + (minusTwoDerangements)%MOD))%MOD;
        minusTwoDerangements = minusOneDerangements;
        minusOneDerangements = curr;
    }
    return minusOneDerangements;
}

long long int countDerangements(int n) {
    return solve(n);
}