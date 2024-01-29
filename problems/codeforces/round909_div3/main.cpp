#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

bool same_parity(int a, int b){
    return abs(a) % 2 == abs(b) % 2;
}

void solve(){
    int n;
    cin >> n;
    vector<int> vals(n, 1);
    for(int i=0; i<n;i++)
        cin >> vals[i];

    vector<int> dp(n, 0);
    dp[0] = vals[0];
    for(int i=1; i<n;i++){
        if(!same_parity(vals[i], vals[i-1]))
            dp[i] = max(dp[i-1] + vals[i], vals[i]);
        else
            dp[i] = vals[i];
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    
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

