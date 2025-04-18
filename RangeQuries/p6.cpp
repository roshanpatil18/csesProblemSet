#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5 + 5;

vector<ll> tree(4 * MAXN);
vector<ll> lazy(4 * MAXN);
vector<ll> arr(MAXN);

// Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = 0; // We only care about updates, not range queries
}

// Propagate lazy updates
void push(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// Range update: add `val` to range [l, r]
void update(int node, int start, int end, int l, int r, ll val) {
    push(node, start, end);

    if (r < start || end < l) return;

    if (l <= start && end <= r) {
        lazy[node] += val;
        push(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
}

// Point query: get value at index `idx`
ll query(int node, int start, int end, int idx) {
    push(node, start, end);

    if (start == end) return tree[node];

    int mid = (start + end) / 2;
    if (idx <= mid)
        return query(2 * node, start, mid, idx);
    else
        return query(2 * node + 1, mid + 1, end, idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        } else {
            int k;
            cin >> k;
            cout << query(1, 1, n, k) << '\n';
        }
    }

    return 0;
}
