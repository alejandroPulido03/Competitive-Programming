#include <iostream>
#include <vector>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve(){
    int a,b,n;
    cin >> a >> b >> n;

    b *= n;
    a = (a * n) + (b / 100);
    b %= 100;

    cout << a << " " << b << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

