#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<tuple<int, int, long long>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    
    // Initialize distances (all zero is a common trick to detect negative cycles
    // in arbitrary graphs) and parent pointers.
    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    
    // Step 1: Relax edges for n-1 times.
    for (int i = 1; i < n; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    
    // Step 2: Check one more time for a relaxation (negative cycle)
    int x = -1;
    for (auto [u, v, w] : edges) {
        if (dist[u] + w < dist[v]) {
            x = v;
            break;
        }
    }
    
    if (x == -1) {
        cout << "NO\n";
    } else {
        // Special handling: if parent[x] is still -1, then the negative cycle
        // comes from a self-loop.
        if (parent[x] == -1) {
            cout << "YES\n" << x << " " << x << "\n";
            return 0;
        }
        
        // Step 3: To ensure that x is within the cycle, follow the parent chain n times.
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }
        
        // Step 4: Reconstruct the cycle starting from x.
        vector<int> cycle;
        int cur = x;
        cycle.push_back(cur);
        cur = parent[cur];
        while (cur != x) {
            cycle.push_back(cur);
            cur = parent[cur];
        }
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());
        
        cout << "YES\n";
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
    
    return 0;
}
