#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> views;
vector<vector<int>> adj;
vector<string> matrix;
vector<bool> marked;
vector<int> components;
vector<int> components_views;

void add_edges(int i, int j, int n, int m) {
    int v = n * i + j;
    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            if ((a != 0 || b != 0) && abs(a) != abs(b) && 0 <= i + a && i + a < m && 0 <= j + b && j + b < n) {
                int u = n * (i + a) + (j + b);
                if (matrix[i + a][j + b] != '*') {
                    adj[v].push_back(u);
                } else {
                    views[v]++;
                }
            }
        }
    }
}

int bfs(int v, int comp) {
    int vi = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (components[top] == -1) {
            components[top] = comp;
            vi += views[top];
        }
        if (!marked[top]) {
            marked[top] = true;
            for (int u : adj[top]) {
                if (!marked[u]) {
                    q.push(u);
                }
            }
        }
    }
    return vi;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    
    adj.resize(n * m);
    views.assign(n * m, 0);
    marked.assign(n * m, false);
    components.assign(n * m, -1);
    
    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        matrix.push_back(row);
    }
    
    vector<int> empty;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != '*') {
                add_edges(i, j, n, m);
                empty.push_back(n * i + j);
            }
        }
    }
    
    int comp = 0;
    for (int i : empty) {
        if (!marked[i]) {
            int vi = bfs(i, comp);
            components_views.push_back(vi);
            comp++;
        }
    }
    
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        row--; // Adjust for 0-based indexing
        col--; // Adjust for 0-based indexing
        int v = n * row + col;
        cout << components_views[components[v]] << endl;
    }
    
    return 0;
}
