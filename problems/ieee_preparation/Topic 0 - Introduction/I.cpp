#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int a , b, Sn, Sa, Sb;
    cin >> a >> b;
    Sn = (b * (b+1) / 2) - (a * (a - 1) / 2);
    Sb = pow(ceil((float) b / 2), 2) - pow(floor((float) a / 2), 2);
    Sa = Sn - Sb;
    cout << (Sa - Sb) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

