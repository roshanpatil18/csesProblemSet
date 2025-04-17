#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;
vector<int> depth;

// DFS to set depth[] and up[][0]
void dfs(int node, int par, const vector<vector<int>>& adj) {
    up[node][0] = par;
    for (int it : adj[node]) {
        if (it == par) continue;
        depth[it] = depth[node] + 1;
        dfs(it, node, adj);
    }
}

// Build the rest of the binary-lifting table
void build_lift(int n) {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            int mid = up[i][j-1];
            up[i][j] = up[mid][j-1];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a,b);

    // 1) Bring a up to depth[b]
    for (int i = LOG-1; i >= 0; i--) {
        if (depth[a] - (1<<i) >= depth[b])
            a = up[a][i];
    }
    if (a == b) return a;

    // 2) Lift both a and b from highest bit down
    for (int i = LOG-1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    // 3) Their parent is LCA
    return up[a][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector<vector<int>> adj(n+1);
    up.assign(n+1, vector<int>(LOG, 0));
    depth.assign(n+1, 0);

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    // 1) DFS to set depth[] and up[][0]
    dfs(1, 0, adj);
    // 2) Build binary lifting table
    build_lift(n);

    // 3) Answer queries
    while (q--) {
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << '\n';
    }
    return 0;
}
