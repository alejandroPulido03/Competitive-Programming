#include <iostream>
#include <vector>
using namespace std;
#define ar array
#define ll long long
#define ld long double

int main(){
    int n, d, m;
    cin >> n >> d;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if(-d <= y-x && y-x <= d && d <= y + x && y + x <= 2*n - d){
            cout << "YES \n";
        }else{
            cout << "NO \n";
        }
    }
    
    return 0;
}

