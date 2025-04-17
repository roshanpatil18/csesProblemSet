#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
int n, m;
vector<int> adj[MAXN+1];
int up[20][MAXN+1], depth[MAXN+1];
long long diffv[MAXN+1];

// 1) preprocess depth[] and up[0][]
void dfs0(int v, int p){
    up[0][v] = p;
    depth[v] = (p == 0 ? 0 : depth[p] + 1);
    for(int u: adj[v]){
        if(u == p) continue;
        dfs0(u, v);
    }
}

// 2) binary lifting build
void build_lca(){
    dfs0(1, 0);
    for(int k = 1; k < 20; k++){
        for(int v = 1; v <= n; v++){
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }
}

// 3) LCA query
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int k = 0; k < 20; k++){
        if(diff & (1<<k)) a = up[k][a];
    }
    if(a == b) return a;
    for(int k = 19; k >= 0; k--){
        if(up[k][a] != up[k][b]){
            a = up[k][a];
            b = up[k][b];
        }
    }
    return up[0][a];
}

// 4) propagate diffs bottom-up
void dfs1(int v, int p){
    for(int u: adj[v]){
        if(u == p) continue;
        dfs1(u, v);
        diffv[v] += diffv[u];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        int a,b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    build_lca();

    // process each query path a–b:
    //   diff[a]++, diff[b]++, diff[lca]--, diff[parent(lca)]-- 
    // then dfs1 to accumulate; diff[v] is #paths through v.
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        int c = lca(a,b);
        diffv[a] += 1;
        diffv[b] += 1;
        diffv[c] -= 1;
        if(up[0][c] != 0){
            diffv[ up[0][c] ] -= 1;
        }
    }

    dfs1(1, 0);

    // output
    for(int v = 1; v <= n; v++){
        cout << diffv[v] << (v==n? '\n' : ' ');
    }
    return 0;
}
