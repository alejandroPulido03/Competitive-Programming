#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int a, b, res;
    cin >> a >> b;
    a = a % 2 == 0 ? a - 1 : a;
    b = b % 2 == 0 ? b - 1 : b;
    res = a - b == 0 ? 1 : floor((double)abs(a - b) / 2);
    cout << res << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

