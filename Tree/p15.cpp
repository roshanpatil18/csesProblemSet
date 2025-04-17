#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
long long ans = 0;

// Returns an array `cnt` where cnt[d] = number of nodes at distance d in this subtree
vector<int> dfs(int u, int p) {
    vector<int> cnt(k+1, 0);
    cnt[0] = 1;  // the node itself

    for (int v : adj[u]) {
        if (v == p) continue;
        auto sub = dfs(v, u);

        // count all pairs (distance i in cnt) + (distance j in sub)
        // such that i + j + 1 == k
        for (int i = 0; i < k; ++i) {
            if (cnt[i] && sub[k - i - 1]) {
                ans += 1LL * cnt[i] * sub[k - i - 1];
            }
        }

        // merge sub into cnt, shifting distances by +1
        for (int i = 1; i <= k; ++i) {
            cnt[i] += sub[i - 1];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    adj.assign(n+1, {});

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}
