#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> ocurrences;
    for (char l : s)
    {
        if (ocurrences.find(l) == ocurrences.end())
            ocurrences.insert({l, 0});
        ocurrences.insert({l, ++ocurrences.find(l)->second});
    }

    auto max_ocur = max_element(ocurrences.begin(), ocurrences.end(), [](const auto &p1, const auto &p2){ return p1.second < p2.second; });
    int sum_elems = accumulate(ocurrences.begin(), ocurrences.end(), 0, [](const auto prev, const auto &p){return prev + p.second;});

    int x = 2 * max_ocur->second - sum_elems;
    cout << (x > 0 ? x : sum_elems % 2) << endl;
    
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
