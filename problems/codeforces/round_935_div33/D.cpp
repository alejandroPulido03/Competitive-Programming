#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll sum = 0;
    for (int i = m; i < n; i++) {
        sum += min(a[i], b[i]);
    }

    ll res = INF;
    ll bSum = 0;
    for (int i = m - 1; i >= 0; i--) {
        res = min(res, a[i] + bSum);
        bSum += b[i];
    }

    cout << sum + res << endl;
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
