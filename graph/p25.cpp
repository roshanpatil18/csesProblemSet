#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN], comp_size[MAXN];

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;  // already in same component
    if (comp_size[a] < comp_size[b]) swap(a, b);
    parent[b] = a;
    comp_size[a] += comp_size[b];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Init DSU
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        comp_size[i] = 1;
    }

    int components = n;
    int max_size = 1;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        if (unite(a, b)) {
            components--;
            max_size = max(max_size, comp_size[find(a)]);
        }

        cout << components << " " << max_size << "\n";
    }

    return 0;
}
