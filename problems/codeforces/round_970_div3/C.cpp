#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

ll find_target(ll t, ll l, ll r){
    ll mid = (l + r) / 2;
    ll val = mid * (mid + 1) / 2;
    //cout << "Val: " << val << " Min: " << l << " Max: " << r << " Mid: " << mid << endl;
    if( val == t )
        return mid;
    if( l == r )
        return mid-1;
    if( val > t)
        return find_target(t, l, mid);
    else // val < t
        return find_target(t, mid+1, r);
}

void solve(){
    int l, r; cin >> l >> r;
    ll target = r - l;
    ll res = find_target(target, 1, target) + 1;
    cout << res << endl;
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

