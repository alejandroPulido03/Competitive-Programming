#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(int m, int n, string map[], int size_m, int size_n) {
  map[m][n] = '*';
  for (int i = max(0, m - 1); i < min(m + 2, size_m); i++)
    for (int j = max(0, n - 1); j < min(n + 2, size_n); j++)
      if (map[i][j] == '@') solve(i, j, map, size_m, size_n);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int m, n;

  cin >> m >> n;
  while (m != 0) {
    string map[m];

    for (int i = 0; i < m; i++) cin >> map[i];

    int pockets = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (map[i][j] == '@') {
          solve(i, j, map, m, n);
          pockets++;
        };
    cout << pockets << endl;
    cin >> m >> n;
  }

  return 0;
}
