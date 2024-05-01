#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    set<int> a = set<int>();
    set<int> b = set<int>();

    vector<pair<int, int>> pairs = vector<pair<int, int>>(n);

    for (int i = 1; i < n; i++) {
        int v, w;
        cin >> v >> w;
        if (v < w)
            pairs[i] = pair<int, int>(v, w);
        else
            pairs[i] = pair<int, int>(w, v);
    }

    sort(pairs.begin(), pairs.end(), [](pair<int, int> &e1, pair<int, int> &e2) { return e1.first < e2.first; });

    for (int i = 1; i < n; i++) {
        int v, w;
        v = pairs[i].first;
        w = pairs[i].second;
        cout << v << " " << w << endl;
        if (i == 1) {
            a.insert(v);
            b.insert(w);
        } else if (a.count(v) != 0) {
            a.insert(v);
            b.insert(w);
        } else {
            a.insert(w);
            b.insert(v);
        }
    }

    int max_e = a.size() * b.size();
    int e = n - 1;
    cout << max_e - e << endl;

    return 0;
}
