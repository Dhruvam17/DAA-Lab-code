#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
int dp[100][100];
int ncr(int n,int r){
    if(r==0)
        return dp [n][r]=1;
        if(r==1)
        return dp [n][r]=n;
        if (n==r)
        return dp [n][r]=1;
        if (dp[n][r]>0)
        return dp[n][r];
        return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
}
int main(){
    int n,r;
    cin>>n>>r;
    int value = ncr(n,r);
    cout<<"Value of combination is "<<value<<endl;
    return 0;
}
