#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    double n, p; cin >> n; cin >> p;p=p/100;
    cout << fixed << setprecision(8) <<(p/pow(p,1/n)-p) * 100 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    int i=0;
    cin >> t;
    while(t--){
        cout << "Case #" << ++i << ": ";
        solve();
    }
    return 0;
}

