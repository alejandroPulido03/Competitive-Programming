#include <iostream>
#include <vector>
using namespace std;
#define ar array
#define ll long long
#define ld long double

int main()
{
    int n;
    string moves;
    int coords[2] = {0, 0};
    int flag = 0;
    int dir = 1;
    cin >> n;
    cin >> moves;
    for (int i = 0; i < moves.size(); i++)
    {
        if (moves[i] == 'S')
        {
            coords[flag % 2] += dir;
        }
        else
        {
            flag++;
            flag %= 4;

            if (flag % 3 != 0)
                dir = -1;
            else
                dir = 1;
        }
    }

    cout << coords[0] << " " << coords[1] << "\n";

    return 0;
}
