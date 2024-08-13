#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void dfs(int u, bool visited[], vector<int> adj[])
{
    visited[u] = true;
    for (int j = 0; j < adj[u].size(); j++)
    {
        int v = adj[u][j];
        if (!visited[v])
            dfs(v, visited, adj);
    }
}

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> adj[n];
    bool visited[n] = {false};
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
    }

    for (int i = 0; i < l; i++)
    {
        int q;
        cin >> q;
        if (!visited[--q])
        {
            dfs(q, visited, adj);
        }
    }

    int vis = 0;
    for (bool v : visited)
        if (v)
            vis++;

    cout << vis << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
