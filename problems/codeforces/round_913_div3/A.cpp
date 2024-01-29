#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

void solve(){
    char pos[2];
    cin >> pos;
    for(char i = 97; i < 97 + 8; i++){
        if(i == pos[0]){
            for(int j = 1; j <=8; j++)
                if(j != (pos[1] - '0'))
                    cout << pos[0] << j << endl;
        }
        else
            cout << i << pos[1] << endl;
        
    }
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

