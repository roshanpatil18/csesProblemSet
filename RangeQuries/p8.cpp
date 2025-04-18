#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> tree(4 * MAXN);
vector<int> hotels;

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = hotels[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// Find the first hotel >= val
int query(int node, int l, int r, int val) {
    if (tree[node] < val) return -1;
    if (l == r) return l;

    int mid = (l + r) / 2;
    if (tree[2 * node] >= val)
        return query(2 * node, l, mid, val);
    else
        return query(2 * node + 1, mid + 1, r, val);
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] -= val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(2 * node, l, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, r, idx, val);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    hotels.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> hotels[i];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int rooms;
        cin >> rooms;

        int idx = query(1, 0, n - 1, rooms);
        if (idx == -1) {
            cout << "0 ";
        } else {
            cout << idx + 1 << " ";
            update(1, 0, n - 1, idx, rooms);
        }
    }

    cout << '\n';
    return 0;
}
