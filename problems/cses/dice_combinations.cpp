#include <iostream>
#include <vector>
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

    ll dp[1000001] = {0};

    dp[0] = 1LL;
    dp[1] = 1LL;
    for (int i = 2; i <= n; i++)
        for (int j = min(i, 6); j >= 1; j--)
            (dp[i] += dp[i - j]) %= MOD;

    cout << dp[n] << "\n";

    return 0;
}
