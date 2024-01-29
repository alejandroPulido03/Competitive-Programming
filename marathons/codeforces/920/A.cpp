#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    int nums[4][2];
    for (int i = 0; i < 4; i++)
        cin >> nums[i][0] >> nums[i][1];
    
    if (nums[0][0] != nums[1][0])
        cout << (ll) pow(abs(nums[0][0] - nums[1][0]), 2) << endl;
    else
        cout << (ll) pow(abs(nums[0][1] - nums[1][1]), 2) << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

