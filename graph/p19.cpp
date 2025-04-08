#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mod=1000000007;
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
    vector<int> dp(n + 1, 0);
                // start at city 1
 dp[1]=1;
    for (int u : topo){
        
        for (int v : num[u]){
            dp[v] = (dp[v] + dp[u]) % mod;
            }
        }
    
cout<<dp[n];


    return 0;
}
