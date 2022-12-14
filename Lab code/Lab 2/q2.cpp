#include <bits/stdc++.h>
using namespace std;

int gcdEuclid(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcdEuclid(b, (a % b));
}

int gcdConsecutiveIntegerChecking(int a, int b)
{
    int temp = min(a, b);
    while (temp)
    {
        if (a % temp == 0 && b % temp == 0)
        {
            return temp;
        }
        else
        {
            temp--;
        }
    }
    return 1;
}

int main()
{
    int a, b;
    cout << "Enter two integers : ";
    cin >> a >> b;
    cout << "(a--> Euclid's Algorithm) GCD of " << a << " and " << b << " : " << gcdEuclid(a, b) << endl;
    cout << "(b--> Consecutive Integer Checking Algorithm) GCD of " << a << " and " << b << " : " << gcdConsecutiveIntegerChecking(a, b) << endl;
    return 0;
}