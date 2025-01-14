/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
*/

/*
Approach :
first, we find the sum of the existing elements in the arr, 
if it is odd, then partition is not possible as we know that odd / 2 is a floating point number, which is not possible for our vector of integers.
if it is even, then we need to find if there exists elements in array whose sum is equal to the sum of entire array / 2.
if YES , then TRUE  else FALSE

we have successfully converted this question into the smaller question of finding a subset whose sum is equal to the sum of partition array.
*/

// Recursion
class Solution
{
    int Sum(int *arr, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    bool solve(int index, int *arr, int n, int targetSum)
    {
        if (targetSum < 0 || index >= n)
        {
            return 0;
        }
        if (targetSum == 0)
        {
            return 1;
        }

        bool inc = solve(index + 1, arr, n, targetSum - arr[index]);
        bool exc = solve(index + 1, arr, n, targetSum);

        return inc || exc;
    }

public:
    int equalPartition(int n, int arr[])
    {
        int sum = Sum(arr, n);
        if (sum & 1)
            return 0;

        int partitionSum = sum / 2;
        return solve(0, arr, n, partitionSum);
    }
};
// memo
class Solution
{
    int Sum(int *arr, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    bool solve(int index, int *arr, int n, int targetSum, vector<vector<int>> &dp)
    {
        if (targetSum < 0 || index >= n)
        {
            return 0;
        }
        if (targetSum == 0)
        {
            return 1;
        }
        if (dp[index][targetSum] != -1)
        {
            return dp[index][targetSum];
        }

        bool inc = solve(index + 1, arr, n, targetSum - arr[index], dp);
        bool exc = solve(index + 1, arr, n, targetSum, dp);
        if (inc || exc)
        {
            dp[index][targetSum] = 1;
        }
        else
        {
            dp[index][targetSum] = 0;
        }
        return dp[index][targetSum];
    }

public:
    int equalPartition(int n, int arr[])
    {

        int sum = Sum(arr, n);
        if (sum & 1)
            return 0;

        int partitionSum = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(partitionSum + 1, -1));
        return solve(0, arr, n, partitionSum, dp);
    }
};
// Tab
class Solution
{
    int Sum(int *arr, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    bool solve(int *arr, int n, int targetSum)
    {
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int sum = 1; sum <= targetSum; sum++)
            {
                bool inc = 0;
                if (sum - arr[index] >= 0)
                    inc = dp[index + 1][sum - arr[index]];
                bool exc = dp[index + 1][sum];

                dp[index][sum] = exc or inc;
            }
        }
        return dp[0][targetSum];
    }

public:
    int equalPartition(int n, int arr[])
    {

        int sum = Sum(arr, n);
        if (sum & 1)
            return 0;

        int partitionSum = sum / 2;
        return solve(arr, n, partitionSum);
    }
};

// So
class Solution
{
    int Sum(int *arr, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    bool solve(int *arr, int n, int targetSum)
    {
        vector<int> curr(targetSum + 1, 0);
        vector<int> next(targetSum + 1, 0);
        curr[0] = next[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int sum = 1; sum <= targetSum; sum++)
            {
                bool inc = 0;
                if (sum - arr[index] >= 0)
                    inc = next[sum - arr[index]];
                bool exc = next[sum];
                curr[sum] = exc or inc;
            }
            next = curr;
        }
        return curr[targetSum];
    }

public:
    int equalPartition(int n, int arr[])
    {

        int sum = Sum(arr, n);
        if (sum & 1)
            return 0;

        int partitionSum = sum / 2;
        return solve(arr, n, partitionSum);
    }
};