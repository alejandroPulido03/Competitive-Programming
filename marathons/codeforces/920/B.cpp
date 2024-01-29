#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    int n;
    string cats;
    string desired;
    cin >> n >> cats >> desired;
    int agg, del;
    agg = 0;
    del = 0;
    for (int i = 0; i < n; i++)
        if(cats[i] != desired[i])
            cats[i] == '0' ? agg++ : del++;
    cout << (ll) max(agg, del) << endl;

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

