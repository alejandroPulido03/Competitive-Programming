/* A - The jackpot */

#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1001

ll solve(int i, int is_g, int n, vector<vector<ll>>& dp, ll* bets) {
  if (i == n) return 0;
  if (dp[i][is_g] == -INF) {
    if (is_g == 1)
      dp[i][is_g] = max(max(solve(i + 1, 1, n, dp, bets), bets[i]),
                        solve(i + 1, 0, n, dp, bets) + bets[i]);
    else
      dp[i][is_g] = bets[i] + max(solve(i + 1, 0, n, dp, bets), 0LL);
  }

  return dp[i][is_g];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n != 0) {
    ll bets[n];
    for (int i = 0; i < n; i++) cin >> bets[i];

    vector<vector<ll>> dp(n, vector<ll>(2, -INF));
    ll res = solve(0, 1, n, dp, bets);

    if (res > 0)
      cout << "The maximum winning streak is " << res << '.' << endl;
    else
      cout << "Losing streak." << endl;
    cin >> n;
  };
  return 0;
}
