#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    int a, b;
    cin >> a >> b;
    if((a%2 == 0 && b%2==0) || (a%2==0 && b%2!=0 && a >= 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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

