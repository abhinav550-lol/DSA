#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    int count = 0;
    vector<bool> v(n, true);
    v[0]=v[1]=false;
    for (int i = 2; i < n ; i++)
    {
        if(v[i]){
        count++;
        for (int j = 2 * i; j < n; j += i)
        {
            v[j] = false;
        }
        }
    }
    return count;
}

int main()
{
    int n = 10;
    cout << countPrimes(7);
    return 0;
}