#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int k, p, s;
    cin >> k >> p >> s;
    cout << floor((float) s / (k * (1 + ((float)p / 100)))) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

