#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int res = 0;

void dfs(int node, int parent, vector<vector<int>>& tree) {
    for (auto child : tree[node]) {
        if (child != parent) {
            dfs(child, node, tree);
            if (ans[child] == 0 && ans[node] == 0) {
                res++;
                ans[child] = 1;
                ans[node] = 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) { // Fix: Read n-1 edges
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a); // Fix: Undirected edge
    }

    ans.resize(n + 1, 0);
    dfs(1, 0, tree); // Start DFS from node 1 with parent 0

    cout << res;
    return 0;
}
