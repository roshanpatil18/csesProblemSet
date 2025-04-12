#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void dfs1(int u, vector<vector<int>> &g, vector<int> &vis) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs1(v, g, vis);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &g, vector<int> &vis) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs2(v, g, vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1), rev_graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    // 1) Order vertices by finish time in original graph
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i, graph, vis);
    }

    // 2) Pick leader = last finished vertex
    int leader = st.top();

    // 3) Check that leader reaches all in original graph
    vector<int> vis_from_leader(n + 1, 0);
    dfs2(leader, graph, vis_from_leader);
    for (int i = 1; i <= n; i++) {
        if (!vis_from_leader[i]) {
            // leader cannot reach i
            cout << "NO\n" << leader << " " << i << "\n";
            return 0;
        }
    }

    // 4) Check that all reach leader (i.e. leader reaches all in reversed graph)
    vector<int> vis_to_leader(n + 1, 0);
    dfs2(leader, rev_graph, vis_to_leader);
    for (int i = 1; i <= n; i++) {
        if (!vis_to_leader[i]) {
            // i cannot reach leader
            cout << "NO\n" << i << " " << leader << "\n";
            return 0;
        }
    }

    // If both checks pass, the graph is strongly connected
    cout << "YES\n";
    return 0;
}
