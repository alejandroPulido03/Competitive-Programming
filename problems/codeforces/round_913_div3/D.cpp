#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

bool enough(int k, vector<array<int, 2>> segs) {
    int l, r;
    l = 0;
    r = 0;
    for (array<int, 2> seg : segs) {
        l = max(l - k, seg[0]);
        r = min(r + k, seg[1]);
        if (l > r)
            return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> segs(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> segs[i][0] >> segs[i][1];

    int l, r;
    l = -1;
    r = INF;

    int mid = (r + l) / 2;

    while (r - l > 1) {
        if (enough(mid, segs))
            r = mid;
        else
            l = mid;

        mid = ((r + l) / 2);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
