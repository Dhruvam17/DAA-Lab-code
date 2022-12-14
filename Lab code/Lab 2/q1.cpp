#include <bits/stdc++.h>
using namespace std;
#define maxRange 50

vector<int> populateArr(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1 + rand() % maxRange;
    }
    return arr;
}

bool checkPrime_Algo1(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
        }
    }
    return isPrime;
}

int countPrimeNumbers(vector<int> arr)
{
    int n = arr.size();
    int primeCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime_Algo1(arr[i]))
        {
            primeCnt++;
        }
    }
    return primeCnt;
}

int main()
{
    int n;
    cout << "Enter the number of integers : ";
    cin >> n;
    vector<int> arr = populateArr(n);
    cout << "Total number of prime numbers : " << countPrimeNumbers(arr) << endl;

    return 0;
}