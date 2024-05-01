#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<int> operands;
    set<string> operations = {"*", "/", "+", "-"};
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string e;
        cin >> e;
        if (operations.find(e) != operations.end())
        {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();

            if (e == "*")
                operands.push(a * b);
            if (e == "+")
                operands.push(a + b);
            if (e == "-")
                operands.push(a - b);
            if (e == "/")
                operands.push(a / b);

        }
        else{
            operands.push(stoi(e));
        }
        
    }

    cout << operands.top() << "\n";

    return 0;
}
