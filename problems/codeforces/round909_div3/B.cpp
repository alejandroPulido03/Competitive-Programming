#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> k;
    auto max_diff = (ll) *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0){
            k.push_back(n / i);
            if(n / i != i)
                k.push_back(i);
        }
    
    for (int val : k) {
        int num_groups = n / val;

        vector<ll> groups(num_groups, 0);
        
        int ind, elems;
        ind = 0;
        elems = 0;
        for (int i = 0; i < n; i++){
            groups[ind] += nums[i];
            elems++;
            elems %= val;
            if(elems == 0)
                ind++;
        }

        max_diff = max(*max_element(groups.begin(), groups.end()) - *min_element(groups.begin(), groups.end()), max_diff);
    }

    cout << max_diff << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
