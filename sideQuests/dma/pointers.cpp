#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int *p;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    p = arr;
    for (int i = 0; i < 10; i++)
    {
        cout << *(p + i) << ' ';
    }
*/
   // void pointers
   int i = 1;
   void *ptr = &i;
   cout<<*ptr;

    return 0;
}