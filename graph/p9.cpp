#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m, q;
vector<vector<pair<int, long long>>> adj;
vector<vector<long long>> dist;

void dijkstra(int src) {
    vector<long long>& d = dist[src];
    d[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top(); pq.pop();
        if (cur_dist > d[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (d[v] > cur_dist + w) {
                d[v] = cur_dist + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    adj.assign(n + 1, {});
    dist.assign(n + 1, vector<long long>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    // Run Dijkstra from every city
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << -1 << "\n";
        else cout << dist[a][b] << "\n";
    }

    return 0;
}
