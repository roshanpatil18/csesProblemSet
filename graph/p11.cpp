#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, ll>>> graph(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    const ll INF = 1e18;
    // dist[node][0]: best cost to node with coupon not used yet
    // dist[node][1]: best cost to node with coupon already used
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;
    
    // Priority queue elements: (current_cost, node, used_coupon_flag)
    using State = tuple<ll, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 0});
    
    while(!pq.empty()){
        auto [d, u, used] = pq.top();
        pq.pop();
        
        // If we have already found a better way, skip
        if(d != dist[u][used]) continue;
        
        // Explore outgoing edges from u
        for(auto &edge : graph[u]){
            int v = edge.first;
            ll w = edge.second;
            
            // Option 1: Do not use coupon on this flight
            if(dist[v][used] > d + w){
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            // Option 2: Use coupon on this flight if it is available
            if(used == 0 && dist[v][1] > d + w/2){  // integer division floors automatically
                dist[v][1] = d + w/2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }
    
    // The answer is the minimum cost to get to city n, regardless of coupon usage.
    cout << min(dist[n][0], dist[n][1]) << "\n";
    
    return 0;
}
