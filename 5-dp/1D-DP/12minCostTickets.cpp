#include <queue>

/*
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour.
*/

//Recursion
int solve(int curr , int n , vector<int> days , vector<int> cost){
    if(curr >= n){ // if we are on the last day of our holiday, we can book no tickets so 0
        return 0;
    }

    int _1DayPass = cost[0] + solve(curr+1 , n , days , cost);

    int i;
    for(i = curr ; i < n && days[i] < days[curr] + 7 ; i++);
    int _7DayPass = cost[1] + solve(i, n , days, cost);


    for(i = curr ; i < n && days[i] < days[curr] + 30 ; i++);
    int _30DayPass = cost[2] + solve(i, n ,days , cost );
    
    return min(_1DayPass , min(_7DayPass , _30DayPass));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   return solve(0 , n , days ,cost);
}

//Memo
int solve(int curr , int n , vector<int> days , vector<int> cost,vector<int> &dp){
    if(curr >= n){
        return 0;
    }
    if(dp[curr] != INT_MAX){
        return dp[curr];
    }
    int _1DayPass = cost[0] + solve(curr+1 , n , days , cost, dp);

    int i;
    for(i = curr ; i < n && days[i] < days[curr] + 7 ; i++);
    int _7DayPass = cost[1] + solve(i, n , days, cost, dp);


    for(i = curr ; i < n && days[i] < days[curr] + 30 ; i++);
    int _30DayPass = cost[2] + solve(i, n ,days , cost, dp );
    
    dp[curr] =  min(_1DayPass , min(_7DayPass , _30DayPass));
    return dp[curr];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   vector<int> dp(n+1, INT_MAX); 
   return solve(0 , n , days ,cost, dp);
}
//Tabulation 
int solve(int n , vector<int> days , vector<int> cost){
   vector<int> dp(n+1, INT_MAX);
   dp[n] = 0; 
   for(int k=n-1 ; k >= 0 ; k--){
       int option1 = cost[0] + dp[k+1];
       int i;
       for( i=k; i < n && days[i] < days[k] + 7; i++ );
       int option2 = cost[1] + dp[i];
       for(i=k; i < n && days[i] < days[k] + 30; i++);
       int option3 = cost[2] + dp[i];

       dp[k] = min(option1 , min(option2 , option3));
    } 
    return dp[0]; // Becuz dp[n] is the cost for last day. so, dp[0] tells the cost from the first day of days.
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   return solve(n , days ,cost);
}

//Queue Approach With o(1) SC solution 
/*
Works via Sliding Window. We remove expired days and add new days on the basis of the current day.
*/


int solve(int n, vector<int> days , vector<int> cost){
    queue<pair<int , int>> week;
    queue<pair<int , int>> month;
    int ans = 0;
    for(auto day : days){
        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }
        while(!month.empty() && month.front().first + 30 <= day ){
            month.pop();
        }
        week.push({day , ans + cost[1]});
        month.push({day , ans + cost[2]});

        ans = min(ans + cost[0] , min(week.front().second, month.front().second));
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   return solve( n, days , cost);
}
