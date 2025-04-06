#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Edge list for Bellman-Ford (storing negated weights)
    vector<tuple<int, int, long long>> edges;
    // For reachability: normal and reverse graph
    vector<vector<int>> graph(n + 1), rgraph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, -c}); // negate weight for maximum score
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    // Bellman-Ford initialization
    const long long INF = 1e18;
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // Standard Bellman-Ford relaxations (n-1 times)
    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Mark nodes reachable from 1
    vector<bool> reachable(n + 1, false);
    {
        queue<int> q;
        q.push(1);
        reachable[1] = true;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : graph[cur]){
                if (!reachable[nxt]){
                    reachable[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }

    // Mark nodes that can reach n using reverse graph
    vector<bool> canReach(n + 1, false);
    {
        queue<int> q;
        q.push(n);
        canReach[n] = true;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : rgraph[cur]){
                if (!canReach[nxt]){
                    canReach[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }

    // Check for a "negative cycle" (i.e. a positive cycle in original)
    // that is reachable from 1 and can reach n
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            // Only consider the cycle if u (or v) is in the "critical" region
            if (reachable[u] && canReach[v]) {
                cout << -1;
                return 0;
            }
        }
    }

    // Output the maximum score: negate the shortest path distance.
    cout << -dist[n];
    return 0;
}
