#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(vector<vector<pair<ll, ll>>> &graph, ll k, ll n, vector<vector<ll>> &dis) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    dis[1][0] = 0;

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if(d>dis[n][k-1]){
            break;
        }

        for (auto [next, cost] : graph[node]) {
            if (dis[next][k - 1] > d + cost) {
                dis[next][k - 1] = d + cost;
                sort(dis[next].begin(), dis[next].end());
                pq.push({d + cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    vector<vector<ll>> dis(n + 1, vector<ll>(k, 1e18));
    solve(graph, k, n, dis);

    for (auto it : dis[n]) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}
