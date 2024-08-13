/* B - Selling Spatulas */

#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1501

int solve(int i, int is_g, float* p, int* t, vector<vector<float>>& dp) {
  if (i == 0) {
    dp[i][is_g] = p[i] - 8;
  } else {
    if (dp[i][is_g] == -INF) {
      if (is_g == 1)
        dp[i][is_g] = max(solve(i - 1, 1, p, t, dp), solve(i, 0, p, t, dp));
      else
        dp[i][is_g] =
            p[i] + max(solve(i - 1, 0, p, t, dp) - (t[i] - t[i - 1]) * 8, -8);
    }
  }
  return dp[i][is_g];
};

void get_bounds(float res, vector<vector<float>>& dp, int& min_b, int& max_b,
                int n, float* p, int* t) {
  for (int i = 0; i < n; i++) {
    if (dp[i][0] == res) {
      float k = 0;
      int j = i;
      for (; j > 0 && k != res; j--) {
        k += p[j] - 8;
        if (k != res) k -= (t[j] - t[j - 1] - 1) * 8;
      }
      if (t[i] - t[++j] < t[max_b] - t[min_b]) {
        max_b = i;
        min_b = j;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  do {
    int t[n];
    float p[n];
    int min_b = 0, max_b = n - 1;
    vector<vector<float>> dp(n, vector<float>(2, -INF));
    for (int i = 0; i < n; i++) {
      cin >> t[i] >> p[i];
      p[i] *= 100;
    };
    float res = solve(n - 1, 1, p, t, dp);

    get_bounds(res, dp, min_b, max_b, n, p, t);
    if (res > 0)
      cout << res / 100 << " " << t[min_b] << " " << t[max_b] << endl;
    else
      cout << "no profit" << endl;

    cin >> n;
  } while (n != 0);

  return 0;
}
