#include <bits/stdc++.h>
using namespace std;

class Disjoint {
public:
    vector<int> rank, parent;

    Disjoint(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUP(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUP(parent[node]);
    }

    void unionr(int u, int v) {
        int pu = findUP(u);
        int pv = findUP(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int solve(int i, int j, int m) {
    return i * m + j;
}

void dfs(int i, int j, vector<vector<char>> &grid, vector<int> &vis, Disjoint &ds, int a, int b, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#') return;

    int cur = solve(i, j, m);
    int par = solve(a, b, m);

    if (vis[cur]) return;
    vis[cur] = 1;

    ds.unionr(cur, par);

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        dfs(ni, nj, grid, vis, ds, a, b, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    Disjoint ds(n * m);
    vector<int> vis(n * m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int id = solve(i, j, m);
                if (!vis[id]) {
                    dfs(i, j, grid, vis, ds, i, j, n, m);
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
