#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define MOD 1000000007
#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(11, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }

    for (int i = 0; i < 11; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << " ";

    cout << endl;

    return 0;
}
