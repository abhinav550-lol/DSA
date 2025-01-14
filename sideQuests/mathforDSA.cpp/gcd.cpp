#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a > b) {
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}

int main()
{
    int num1, num2;
    cout << "Enter the two numbers to find GCD/HCF of" << endl;
    cin >> num1>>num2;
    int hcf=gcd(num1, num2);
    cout << "The GCD is " << hcf<<endl;
    
    int lcm, prod;
    prod=num1*num2;
    lcm=prod/gcd(num1,num2);
    cout<<"The LCM is: "<<lcm<<endl;
    return 0;
}