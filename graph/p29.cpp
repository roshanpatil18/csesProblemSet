#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 1) Read coin values
    vector<ll> coin(n);
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    // 2) Read graph and build reverse graph
    vector<vector<int>> g(n), gr(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    // 3) Kosaraju's first pass: order by finish time
    vector<bool> used(n,false);
    vector<int> order;
    order.reserve(n);

    function<void(int)> dfs1 = [&](int u){
        used[u] = true;
        for(int v : g[u])
            if(!used[v])
                dfs1(v);
        order.push_back(u);
    };

    for(int i = 0; i < n; i++){
        if(!used[i])
            dfs1(i);
    }

    // 4) Kosaraju's second pass: assign components
    vector<int> comp(n, -1);
    int scc_cnt = 0;

    function<void(int)> dfs2 = [&](int u){
        comp[u] = scc_cnt;
        for(int v : gr[u])
            if(comp[v] == -1)
                dfs2(v);
    };

    for(int i = n - 1; i >= 0; i--){
        int u = order[i];
        if(comp[u] == -1){
            dfs2(u);
            scc_cnt++;
        }
    }

    // 5) Compute SCC-weights (sum of coins in each component)
    vector<ll> scc_value(scc_cnt, 0);
    for(int u = 0; u < n; u++){
        scc_value[comp[u]] += coin[u];
    }

    // 6) Build condensed DAG of SCCs, track in-degrees
    vector<vector<int>> dag(scc_cnt);
    vector<int> indeg(scc_cnt, 0);

    for(int u = 0; u < n; u++){
        for(int v : g[u]){
            int cu = comp[u], cv = comp[v];
            if(cu != cv){
                dag[cu].push_back(cv);
                indeg[cv]++;
            }
        }
    }

    // 7) Topological DP on the DAG (Kahn's algorithm)
    vector<ll> dp(scc_cnt, 0);
    queue<int> q;
    // Initialize: for every SCC with indegree 0, dp = its own value
    for(int c = 0; c < scc_cnt; c++){
        if(indeg[c] == 0){
            q.push(c);
            dp[c] = scc_value[c];
        }
    }

    ll answer = 0;
    while(!q.empty()){
        int c = q.front(); q.pop();
        // update global maximum
        answer = max(answer, dp[c]);
        // relax outgoing edges
        for(int nxt : dag[c]){
            dp[nxt] = max(dp[nxt], dp[c] + scc_value[nxt]);
            if(--indeg[nxt] == 0)
                q.push(nxt);
        }
    }

    cout << answer << "\n";
    return 0;
}
