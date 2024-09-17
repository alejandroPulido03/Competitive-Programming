#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000


void solve(){
    int n;cin>>n;
    string s; cin >> s;
    if(n%2==1){
        int pr_even[26][n] = {0};
        int pr_odd[26][n] = {0};
        int sf_even[26][n] = {0};
        int sf_odd[26][n] = {0};

        for(int i=0; i<n; i++){
            if(i%2==0)
                pr_even[s[i] - 'a'][i]++;
            else
                pr_odd[s[i] - 'a'][i]++;
            if(n-i-1 % 2 == 0)
                sf_even[s[i] - 'a'][i]++;
            else
                sf_odd[s[i] - 'a'][i]++;
        }

        int max_even = 0;
        int max_odd = 0;

        for(int i=0; i<n-2; i++){
            if(i%2==0)
                max_even = max(max_even, pr_even[s[i] - 'a'][i] + sf_odd[s[i] - 'a'][i+2]);
            else
                max_odd = max(max_odd, pr_odd[s[i] - 'a'][i] + sf_even[s[i] - 'a'][i+2]);
        }
        cout << "Even: " << max_even << endl;
        cout << "Odd: " << max_odd << endl;
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

