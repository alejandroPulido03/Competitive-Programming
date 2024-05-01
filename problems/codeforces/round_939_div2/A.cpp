#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve() {
    int k, q;
    cin >> k >> q;
    int ki[k];

    for (int i = 0; i < k; i++)
        cin >> ki[i];
    for (int i = 0; i < q; i++) {
        int qi;
        cin >> qi;
        if (qi < ki[0])
            cout << qi << (i < q - 1 ? " " : "");
        else
            cout << ki[0] - 1 << (i < q - 1 ? " " : "");
    }
    cout << endl;
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
