#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int n;
    cin >> n;
    cout << (n == 0 ? 0 : n/abs(n)) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

