#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l;
    cin >> l;
    vector<ll> cut_prices(l + 1, 0);
    vector<ll> dp(l + 1, -INF);

    for (int i = 1; i <= l; i++)
        cin >> cut_prices[i];

    dp[1] = cut_prices[1];
    for (int i = 2; i <= l; i++)
    {
        for (int j = 1; j < i; j++)
            dp[i] = max(dp[j] + dp[i - j], cut_prices[i]);
    }

    cout << dp[l] << endl;
    return 0;
}
