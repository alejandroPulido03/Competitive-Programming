#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void dfs(int node, auto adj, bool visited[])
{
    visited[node] = true;
    for (int v : adj[node])
        if (!visited[v])
            dfs(v, adj, visited);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    bool visited[n] = {false};

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0, adj, visited);

    bool flag = false;
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            cout << i + 1 << endl;
            flag = true;
        }

    if (!flag)
        cout << "Connected" << endl;

    return 0;
}
