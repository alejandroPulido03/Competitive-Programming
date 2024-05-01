#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve() {
    int n;
    cin >> n;
    set<int> cards = set<int>();
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (cards.count(a) == 0)
            cards.insert(a);
        else
            pairs++;
    }
        cout << pairs << endl;
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
