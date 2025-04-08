#include <bits/stdc++.h>
using namespace std;

int k;
bool dfs(vector<vector<int>> &graph, int node, vector<int> &vis, vector<int> &par, vector<int> &path) {
    vis[node] = 1;
    path[node] = 1;

    for (auto it : graph[node]) {
        if (!vis[it]) {
            par[it] = node;
            if (dfs(graph, it, vis, par, path)) return true;
        } else if (path[it]) {
            k = it;
            par[it] = node;
            return true;
        }
    }

    path[node] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, -1);
    vector<int> path(n + 1, 0);

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(graph, i, vis, par, path)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct the cycle
    vector<int> cycle;
    cycle.push_back(k);
    int curr = par[k];
    while (curr != k) {
        cycle.push_back(curr);
        curr = par[curr];
    }
    cycle.push_back(k);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int x : cycle) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
