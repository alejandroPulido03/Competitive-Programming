#include <iostream>
#include <vector>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int n;
    cin >> n;
    
    cout << ((n % 2 == 0) ? n + 2 : n+1) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

