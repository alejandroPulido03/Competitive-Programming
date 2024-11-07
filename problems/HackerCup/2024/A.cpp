#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    ll n, k;cin>>n;cin>>k;
    ll min_si;
    for(ll i=0;i<n;i++){
        ll s_i; cin>>s_i;
        min_si = min(min_si, s_i);
    }
    ll res = min_si * 2 * max(n-2, 0LL) + min_si;
    cout << ( res <= k ? "YES" : "NO") << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    int i = 0;
    cin >> t;
    while(t--){
        cout << "Case #" << ++i << ": ";
        solve();
    }
    return 0;
}

