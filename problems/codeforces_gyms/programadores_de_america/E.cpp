#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

void solve() {
    int n;
    cin >> n;
    vector<char> stack = vector<char>();
    vector<char> out_stack = vector<char>();
    set<char> marked = set<char>();
    

    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        if (a == '+')
            stack.push_back(b);
        else
            out_stack.push_back(b);
        marked.insert(b);
    }

    for (char x : out_stack) {
        for (char comp : stack) {
            if (comp == x)
                break;
            if (marked.count(comp) != 0){
                marked.erase(comp);
                
            }
        }
    }

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
