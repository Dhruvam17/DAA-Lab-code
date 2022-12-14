#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int i, vector<vector<int>> adj, vector<int> &vis, vector<int> &ans)
{
    int n = adj.size();
    vis[i] = 1;
    ans.push_back(i);
    for (int j = 1; j <= n; j++)
    {
        if (adj[i][j] == 1 && vis[j] == 0 && i != j)
        {
            dfsUtil(j, adj, vis, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>> adj)
{
    if (adj.size() == 0)
    {
        return {};
    }
    int n = adj.size();
    vector<int> vis(n + 1, 0), ans;
    for (int i = 1; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfsUtil(i, adj, vis, ans);
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        int m;
        adj[i][i] = 1;
        cout << "No. of adjacent nodes to node  " << i << " : ";
        cin >> m;
        int k = 1;
        while (m--)
        {
            int x;
            cout << "Enter adjacent node no. " << k++ << " : ";
            cin >> x;
            if (x > 0 && x <= n && x != i)
            {
                adj[i][x] = 1;
                adj[x][i] = 1;
            }
            else
            {
                cout << "Invalid input" << endl;
                return 0;
            }
        }
    }

    vector<int> dfsResult = dfs(adj);

    for (int i = 0; i < dfsResult.size(); i++)
    {
        cout << dfsResult[i] << " ";
    }

    return 0;
}