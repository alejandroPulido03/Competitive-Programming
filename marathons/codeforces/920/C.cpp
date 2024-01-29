#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    ll last_m = 0;

    bool enough = true;
    for(int i = 0; i < n; i++){
        ll curr_m;
        cin >> curr_m;
        f -= min(b, (curr_m - last_m) * a);
        
        last_m = curr_m;
        if (f <= 0)
            enough = false;  
    }
    
    cout << (enough ? "YES" : "NO") << endl;

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

