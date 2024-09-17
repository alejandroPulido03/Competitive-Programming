#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

int dfs(int i, int* visited, int* adj, string& i_c, int id ){
    if(visited[i] == 0){
        visited[i] = id;
        int res = i_c[i] == '0' ? 1 : 0;
        res += dfs(adj[i], visited, adj, i_c, id);
        return res;
    }
    return 0;
}

void solve(){
    int n;cin>>n;
    int visited[n] = {0};
    int adj[n];
    for(int i=0;i<n;i++){
        int elem;cin>>elem;
        adj[i] = --elem;
    }
    string i_c;cin>>i_c;

    int id = 1;
    vector<int> res = vector<int>();
    for(int i=0;i<n;i++)
        if(visited[i] == 0)
            res.push_back(dfs(i, visited, adj, i_c, id++));

    for(int i=0; i < n; i++)
        cout << res[visited[i]-1] << " ";
    cout << endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

