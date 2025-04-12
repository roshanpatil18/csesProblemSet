#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Edge {
    int u, v;
    ll cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

vector<int> parent, sz;

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = {a - 1, b - 1, c};
    }

    // Sort by cost
    sort(edges.begin(), edges.end());

    parent.resize(n);
    sz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);

    ll total = 0;
    int used = 0;

    for (auto &e : edges) {
        if (unite(e.u, e.v)) {
            total += e.cost;
            used++;
            if (used == n - 1) break; // MST complete
        }
    }

    if (used == n - 1)
        cout << total << '\n';
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}
