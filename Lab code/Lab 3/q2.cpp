#include<bits/stdc++.h>
using namespace std;

void finda(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;
        }
        if(count>=n/2)
        {
        cout<<arr[i]<<" ";
        }
    }
}


void findb(int arr[],int n)
{
    unordered_map<int,int>ump;
    for(int i=0;i<n;i++)
    {
        ump[arr[i]]++;
    }
    for(auto i : ump)
    {
        if(i.second>=n/2)
        cout<<i.first<<" ";
    }
}

int main()
{
    cout<<"INPUT SIZE OF ARRAY : ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%n/5;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    cout<<"\n";
    cout<<"TIME COMPLEXITY O(N^2) WITH NO SPACE : ";
    finda(arr,n);
    cout<<"\nTIME COMPLEXITY O(N) WITH O(N) SPACE : ";
    findb(arr,n);
    return 0;
}