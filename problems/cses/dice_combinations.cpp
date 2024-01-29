#include <iostream>
#include <vector>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    ll dp[1000001] = {0};

    for (ll i = 0; i <= n; i++)
    {
        if (i <= 1)
            dp[i] = 1LL;
        else
        {
            for (int j = 1; j <= min(6LL, i); j++)
            {
                (dp[i] += dp[i - j]) %= MOD;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
