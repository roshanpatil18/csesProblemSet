#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
vector<int> tree(4 * MAXN);
int n;

// Build segment tree
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Remove k-th alive element, return its index (0-based)
int remove(int node, int l, int r, int k) {
    if (l == r) {
        tree[node] = 0;
        return l - 1; // convert to 0-based index
    }
    int mid = (l + r) / 2, idx;
    if (tree[2 * node] >= k)
        idx = remove(2 * node, l, mid, k);
    else
        idx = remove(2 * node + 1, mid + 1, r, k - tree[2 * node]);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> arr(n), pos(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) cin >> pos[i];

    build(1, 1, n);

    for (int i = 0; i < n; ++i) {
        int idx = remove(1, 1, n, pos[i]);
        cout << arr[idx] << " ";
    }

    cout << "\n";
    return 0;
}
