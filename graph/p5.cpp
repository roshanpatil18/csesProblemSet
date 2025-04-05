#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

bool iscycle(vector<vector<int>> &temp, vector<int> &vis, int node) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    vis[node] = 1;
    ans[node] = 0;

    while (!q.empty()) {
        int no = q.front().first;
        int co = q.front().second;
        q.pop();

        for (auto it : temp[no]) {
            if (!vis[it]) {
                q.push({it, 1 - co});
                vis[it] = 1;
                ans[it] = 1 - co;
            } else if (ans[it] == co) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> num;
    vector<vector<int>> temp(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        num.push_back({a, b});
        temp[a].push_back(b);
        temp[b].push_back(a);
    }

    ans.resize(n + 1, -1);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && iscycle(temp, vis, i)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}
