#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> parent(N, -1);
vector<int> visited(N, 0);
int start = -1, endd = -1;

bool dfs(int u, int par) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (visited[v]) {
            start = v;
            endd = u;
            return true;
        } else {
            parent[v] = u;
            if (dfs(v, u)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build graph
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Try DFS from every unvisited node
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                // Found a cycle
                vector<int> cycle;
                cycle.push_back(start);
                int x = endd;
                while (x != start) {
                    cycle.push_back(x);
                    x = parent[x];
                }
                cycle.push_back(start);
                reverse(cycle.begin(), cycle.end());
                cout << cycle.size() << "\n";
                for (int city : cycle) cout << city << " ";
                return 0;
            }
        }
    }

    // No cycle
    cout << "IMPOSSIBLE\n";
    return 0;
}
