#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> addNsub(int *arr,int size)
{
    int add=0, sub=0;
    for(int i = 0; i<size;i++){
        add+=arr[i];
        sub-=arr[i];
    }
    return make_pair(add,sub);
}

int main()
{
    int arr[4]={14,21,12,32};
    pair<int,int> res[2]=addNsub(arr,4);
    cout<<res->first;
    cout<<res->second;
    return 0;
}