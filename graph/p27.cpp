#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>> &graph, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (int nei : graph[node]) {
        if (!vis[nei]) dfs1(nei, graph, vis, st);
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>> &rev_graph, vector<int> &vis, int label, vector<int> &res) {
    vis[node] = 1;
    res[node] = label;
    for (int nei : rev_graph[node]) {
        if (!vis[nei]) dfs2(nei, rev_graph, vis, label, res);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1), rev_graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a); // reversed edge
    }

    vector<int> vis(n + 1, 0);
    stack<int> st;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs1(i, graph, vis, st);
    }

    fill(vis.begin(), vis.end(), 0);
    vector<int> res(n + 1, 0);
    int label = 0;

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!vis[node]) {
            ++label;
            dfs2(node, rev_graph, vis, label, res);
        }
    }

    cout << label << "\n";
    for (int i = 1; i <= n; ++i) cout << res[i] << " ";
    cout << "\n";
}
