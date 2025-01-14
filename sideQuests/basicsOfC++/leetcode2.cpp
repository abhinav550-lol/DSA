#include <iostream>
#include <cmath>
using namespace std;

int compliment(int a)
{
    if (a == 0)
    {
        return 1;
    }
    int comp = 0, i = 0;
    while (a != 0)
    {
        int bit = a & 1;
        if (bit == 0)
        {
            comp += pow(2, i);
        }
        i++;
        a = a >> 1;
    }
    return comp;
}

int main()
{
    int a;
    cin >> a;
    cout << compliment(a);
    return 0;
}