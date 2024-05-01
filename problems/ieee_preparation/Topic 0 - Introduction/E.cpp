#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve()
{
    int n, k;
    cin >> n >> k;
    int res = ceil((double) n / k) * k - n;
    cout << res << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
