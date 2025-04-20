#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int MAXN = 2e5 + 5;

int t1[4 * MAXN]; // for p[i] - i
int t2[4 * MAXN]; // for p[i] + i
int n, q;

void build(int node, int l, int r, const vector<int> &p) {
    if (l == r) {
        t1[node] = p[l] - l;
        t2[node] = p[l] + l;
    } else {
        int mid = (l + r) / 2;
        build(2 * node, l, mid, p);
        build(2 * node + 1, mid + 1, r, p);
        t1[node] = min(t1[2 * node], t1[2 * node + 1]);
        t2[node] = min(t2[2 * node], t2[2 * node + 1]);
    }
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        t1[node] = val - idx;
        t2[node] = val + idx;
    } else {
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);
        t1[node] = min(t1[2 * node], t1[2 * node + 1]);
        t2[node] = min(t2[2 * node], t2[2 * node + 1]);
    }
}

int query_t1(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INF;
    if (ql <= l && r <= qr) return t1[node];
    int mid = (l + r) / 2;
    return min(query_t1(2 * node, l, mid, ql, qr),
               query_t1(2 * node + 1, mid + 1, r, ql, qr));
}

int query_t2(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INF;
    if (ql <= l && r <= qr) return t2[node];
    int mid = (l + r) / 2;
    return min(query_t2(2 * node, l, mid, ql, qr),
               query_t2(2 * node + 1, mid + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    build(1, 1, n, p);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            p[k] = x;
            update(1, 1, n, k, x);
        } else {
            int k;
            cin >> k;
            int res1 = query_t1(1, 1, n, 1, k) + k;
            int res2 = query_t2(1, 1, n, k, n) - k;
            cout << min(res1, res2) << '\n';
        }
    }

    return 0;
}
