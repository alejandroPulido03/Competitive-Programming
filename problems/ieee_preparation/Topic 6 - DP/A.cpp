#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double

int main(){    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> n_sums(n + 1, 0);

    cin >> n_sums[1];
    for (int i = 2; i < n + 1; i++)
    {
        cin >> n_sums[i];
        n_sums[i] += n_sums[i-1];
    }
    
    int l, r;
    while(q--)
    {
        cin >> l >> r;
        cout << n_sums[r] - n_sums[l] << endl;
    }
    
    return 0;
}

