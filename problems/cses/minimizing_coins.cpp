#include <bits/stdc++.h>
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

    int n, x, num_coins;
    cin >> x >> n;
    vector<int> coins(x);
    vector<int> dp(n + 1, INF);
    for (int i = 0; i < n; i++) cin >> coins[i];

    dp[0] = 0;
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < x; j++){
            if (coins[j] <= i)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);    
        }
    
    }
    
    dp[n] = dp[n] == INF ? -1 : dp[n];
    cout << dp[n] << "\n";

    return 0;
}
