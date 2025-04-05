#include <bits/stdc++.h>
using namespace std;

int res = 0;

bool bfs(vector<vector<int>> &temp, int node, int dest, vector<int> &t) {
    int n = temp.size();
    vector<int> vis(n, 0);
    queue<int> q;
    t[node] = -1;

    q.push(node);
    vis[node] = 1;

    while (!q.empty()) {
        int k = q.front();
        q.pop();
        res++;

        if (k == dest) {
            return true;
        }

        for (auto it : temp[k]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
                t[it] = k;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Make graph size n+1 for 1-based indexing
    vector<vector<int>> temp(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        temp[a].push_back(b);
        temp[b].push_back(a);
    }

    vector<int> t(n + 1, -1);

    int start = 1, dest = n;

    if (!bfs(temp, start, dest, t)) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(curr);
            curr = t[curr];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int x : path) cout << x << " ";
    }

    return 0;
}
