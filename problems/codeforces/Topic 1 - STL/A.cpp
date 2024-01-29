#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double

void solve()
{
    stack<char> s;
    map<char, char> pairs;
    string l;

    pairs = {{'}', '{'}, {']', '['}, {')', '('}};
    cin >> l;
    for (int i = 0; i < l.size(); i++)
    {
        char si = l.at(i);

        if (!s.empty() && pairs.find(si) != pairs.end() && pairs.at(si) == s.top()){
            s.pop();
        }else{
            s.push(si);
        }
    }

    cout << (s.empty() ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
