#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve() {
    double n;
    cin >> n;
    string a;
    cin >> a;
    int s = 0;
    int sa = 0;
    double dist = n;
    int i_s = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == '1')
            s++;

    if (s >= ceil(n / 2))
        dist = abs(n / 2);

    for (double i = 1; i < a.length() + 1; i++) {
        if (a[i - 1] == '1')
            s--;
        else
            sa++;
        if (s >= ceil((n - i) / 2) && sa >= ceil(i / 2) && dist > abs(n / 2 - i)) {
            dist = abs(n / 2 - i);
            i_s = i;
        }
    }
    cout << i_s << endl;
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
