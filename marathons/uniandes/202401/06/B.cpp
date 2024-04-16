#include <bits/stdc++.h>
using namespace std;

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 100000;
state st[MAXLEN * 2];

int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

bool sa_walk(string c) {
    state head = st[0];
    for (char i : c) {
        if (head.next.count(i)) {
            int head_ind = head.next[i];
            head = st[head_ind];
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;

    sa_init();
    for (char i : n) {
        sa_extend(i);
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string k_i;
        cin >> k_i;
        cout << (sa_walk(k_i) ? "YES" : "NO") << endl;
    }

    return 0;
}
