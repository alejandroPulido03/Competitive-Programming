#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve(){
    int n; cin >> n;
    int side = sqrt(n);
    string square;cin>>square;
    if(side*side == n){
        bool is_sq = true;
        for(int i=0;i<side;i++){
            for(int j=0;j<side;j++){
                if(i == 0 || i == side-1 || j == 0 || j == side-1)
                    is_sq = is_sq && square[i*side+j] == '1';
                else
                    is_sq = is_sq && square[i*side+j] == '0';
            }
        }
        cout << (is_sq ? "Yes" : "No") <<endl;
    }else{
        cout << "No" << endl;
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

