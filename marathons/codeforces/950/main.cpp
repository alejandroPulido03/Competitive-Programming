#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve()
{
    int m, n;
    string a;
    cin >> n >> m;
    cin >> a;
    map<char, int> rounds = map<char, int>();

    for (char l : "ABCDEFG")
        rounds[l] = 0;

    for (char l : a)
        rounds[l]++;

    int sum = 0;

    for (auto v = rounds.begin(); v != rounds.end(); v++)
    {
        sum += max(m - v->second, 0);
    }

    cout << sum - m << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
