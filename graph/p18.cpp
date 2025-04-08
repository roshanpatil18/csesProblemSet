#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> num(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        num[a].push_back(b);
        indegree[b]++;
    }

    // 1) Toposort (Kahn)
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    topo.reserve(n);
    while (!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : num[u]){
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    // 2) Longest-path DP
    vector<int> dp(n + 1, 0), par(n + 1, -1);
    dp[1] = 1;               // start at city 1

    for (int u : topo){
        if (dp[u] == 0)      // unreachable from 1
            continue;
        for (int v : num[u]){
            if (dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
        }
    }

    // 3) Check reachability
    if (dp[n] == 0){
        // no path from 1 to n
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // 4) Reconstruct path safely
    vector<int> path;
    int c = n;
    while (c != -1){
        path.push_back(c);
        if (c == 1) 
            break;
        c = par[c];
    }

    // If we didn't end up at 1, something went wrong
    if (path.back() != 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path)
        cout << x << " ";
    cout << "\n";


    return 0;
}
