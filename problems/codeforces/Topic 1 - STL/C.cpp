
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
 
int main(){    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    queue<int> players;

    int max_elem = -1;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        max_elem = max(max_elem, a);
        players.push(a);
    }

    if(n < k)
        cout << max_elem << "\n";
    else{
        int curr_win = players.front(), wins = 0;
        players.pop();

        while(k > wins){
            int curr_player = players.front();
            players.pop();

            if(curr_player > curr_win){
                players.push(curr_win);
                curr_win = curr_player;
                wins = 1;
            }else{
                players.push(curr_player);
                wins++;
            }
        }

        cout << curr_win << "\n";
    }

    return 0;
}
 
// Demostrar que para todo lenguaje sobre un alfabeto, existe un lenguaje 
// Existe un lenguaje que no tiene una gramatica que lo genere

    /* while (true)
    {
        int player = players.front();
        players.pop();

        if (wins == k || curr_winner == player)
        {
            cout << curr_winner << "\n";
            return 0;
        }

        if (curr_winner > player)
        {
            wins++;
            players.push(player);
        }
        else
        {
            players.push(player);
            players.push(curr_winner);
            curr_winner = player;
            wins = 0;
        }
    } */

