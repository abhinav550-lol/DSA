#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void allSubsets(string s, vector<string> &result, string subsequence, int index)
{
    if (s.size() <= index)
    {
        if (subsequence.length() > 0)
        {
            result.push_back(subsequence);
        }
        return;
    }
    allSubsets(s, result, subsequence, index + 1);

    subsequence.push_back(s[index]);
    allSubsets(s, result, subsequence, index + 1);
}

vector<string> subsequences(string s)
{
    string subsequence = "";
    vector<string> result;
    int index = 0;

    allSubsets(s, result, subsequence, index);
    return result;
}

int main()
{
    string s = "abc";
    vector<string> result = subsequences(s);
    for (string subset : result)
        cout << subset << ' ';
    return 0;
}