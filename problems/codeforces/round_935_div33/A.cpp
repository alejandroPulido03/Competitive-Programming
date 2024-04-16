#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b % 3 != 0 && 3 - (b % 3) > c) {
        cout << "-1" << endl;
    } else {
        int res;
        res = a;
        
        if (b % 3 != 0) {
            res += (b + 3 - (b % 3)) / 3;
            c -= 3 - (b % 3);
        }else{
            res += b / 3;
        }
        res += c / 3 + min(c % 3, 1);
        

        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
