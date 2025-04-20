#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum, prefix;
};

const int MAXN = 2e5 + 5;
Node seg[4 * MAXN];
int n, q;
vector<long long> arr;

Node merge(Node a, Node b) {
    return {
        a.sum + b.sum,
        max(a.prefix, a.sum + b.prefix)
    };
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = {arr[l], max(0LL, arr[l])};
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    seg[idx] = merge(seg[2*idx], seg[2*idx+1]);
}

void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) {
        seg[idx] = {val, max(0LL, val)};
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2*idx, l, mid, pos, val);
    else
        update(2*idx+1, mid+1, r, pos, val);
    seg[idx] = merge(seg[2*idx], seg[2*idx+1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r)
        return {0, 0}; // neutral element
    if (ql <= l && r <= qr)
        return seg[idx];
    int mid = (l + r) / 2;
    Node left = query(2*idx, l, mid, ql, qr);
    Node right = query(2*idx+1, mid+1, r, ql, qr);
    return merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    build(1, 1, n);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update(1, 1, n, a, b);
        } else {
            cout << query(1, 1, n, a, b).prefix << '\n';
        }
    }

    return 0;
}
