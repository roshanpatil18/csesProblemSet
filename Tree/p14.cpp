#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void dfs(int node, int par, vector<vector<int>>& adj) {
    for (auto it : adj[node]) {
        if (it != par) {
            dfs(it, node, adj);
            ans[node] += ans[it];
        }
    }
}

int dfs2(int n, int node, int par, vector<vector<int>>& adj) {
    for (auto it : adj[node]) {
        if (it != par) {
            if (ans[it] > n / 2) {
                return dfs2(n, it, node, adj); // go deeper
            }
        }
    }
    return node; // current node is centroid
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans.resize(n + 1, 1);
    dfs(1, 0, adj);

    cout << dfs2(n, 1, 0, adj) << "\n"; // centroid of the tree
}
