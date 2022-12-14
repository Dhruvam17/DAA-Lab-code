#include <bits/stdc++.h>
using namespace std;

int lcsUtil(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i - 1] == s[j - 1])
    {
        return dp[i][j] = 1 + lcsUtil(i - 1, j - 1, s, t, dp);
    }
    else
    {
        int moveI = lcsUtil(i - 1, j, s, t, dp);
        int moveJ = lcsUtil(i, j - 1, s, t, dp);
        return dp[i][j] = max(moveI, moveJ);
    }
}

string printSubstring(string s, string t, vector<vector<int>> dp)
{
    int m = s.size(), n = t.size();
    string ansString = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ansString += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ansString.begin(), ansString.end());
    return ansString;
}

int lcs(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    int ans = lcsUtil(m, n, s, t, dp);

    cout << printSubstring(s, t, dp) << endl;

    return ans;
}

int main()
{
    string s = "dhruvam", t = "subham";
    cout << lcs(s, t) << endl;

    return 0;
}