#include <bits/stdc++.h>
using namespace std;

vector<long long> ans;

void solve(vector<vector<pair<int, long long>>>& adj, int node) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, node});
    ans[node] = 0;

    while (!pq.empty()) {
        long long dis = pq.top().first;
        int no = pq.top().second;
        pq.pop();

        if (dis > ans[no]) continue;

        for (auto it : adj[no]) {
            int a = it.first;
            long long h = it.second;
            if (ans[a] > h + dis) {
                ans[a] = h + dis;
                pq.push({ans[a], a});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    ans.resize(n + 1, 1e18);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    solve(adj, 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
