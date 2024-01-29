#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define INF 1000000000
#define MOD 1000000007

void solve()
{
    string s;
    int a, b;
    cin >> s;
    a = b = s.length();

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            for (int j = min(a, i); j >= 0; j--)
            {
                if (s[j] != 'b' && s[j] != '$' && s[j] == tolower(s[j]))
                {
                    s[j] = '$';
                    break;
                }
                a = j;
            }
        }
        else if (s[i] == 'B')
        {
            for (int j = min(b, i); j >= 0; j--)
            {
                if (s[j] != 'B' && s[j] != '$' && s[j] == toupper(s[j]))
                {
                    s[j] = '$';
                    break;
                }
                b = j;
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '$' && s[i] != 'B' && s[i] != 'b')
            cout << s[i];
    cout << endl;
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
