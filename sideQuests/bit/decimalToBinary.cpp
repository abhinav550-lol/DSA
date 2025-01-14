#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n;
  cin >> n;

  float nInBits = 0;
  int i=0;
  while (n != 0)
  {
    int bit = n & 1;
    nInBits = (bit * pow(10, i))+nInBits ;
    n = n >> 1;//ok
    i++;
  }
  cout << nInBits;

  return 0;
}