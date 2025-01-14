#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int stringlenn(char str[])
{
    int length = 0;
    for(int i=0;str[i]!='\0';i++){
        length++;
    }
    return length;
}

int main()
{
    char s1[20];
    cin >> s1;
    int len=stringlenn(s1);
    cout<<len;
    return 0;
}