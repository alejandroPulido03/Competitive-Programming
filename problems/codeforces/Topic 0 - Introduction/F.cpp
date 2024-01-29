#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int a, b, l, n;
    cin >> a >> b >> l >> n;
    cout << l * 2 + b * (n - 1) * 2 + a * (n - 1) * 2 + a << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

