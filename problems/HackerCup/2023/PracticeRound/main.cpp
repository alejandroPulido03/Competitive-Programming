#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve()
{
    int s, d, k;
    cin >> s >> d >> k;

    int min_c = min(s, d);
    int count = min_c * 3;
    d -= min_c;
    s -= min_c;
    count += d > 0 ? (2 * d) - 1 : 0;
    count += s;

    cout << (count >= k ? "YES" : "NO") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, i;
    i = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}
