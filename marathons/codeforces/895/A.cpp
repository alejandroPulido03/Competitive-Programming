#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    double mid = (double)(a + b) / 2;
    
    cout << ceil(abs(a - mid)/ c) << endl;
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

