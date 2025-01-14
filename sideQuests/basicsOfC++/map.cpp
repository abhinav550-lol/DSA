#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
int arr[10] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 7};
map<int, bool> visited;
for(int i=0;i<10;i++){
        if (visited[arr[i]]==false){
            cout<<arr[i]<<" ";
            visited[arr[i]]=true;
        }
    }

     return 0;
}