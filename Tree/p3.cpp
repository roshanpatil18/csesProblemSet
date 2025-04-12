#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj;

pair<int, int> bfs(int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farthest_node = start;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthest_node]) {
                    farthest_node = neighbor;
                }
            }
        }
    }

    return {farthest_node, dist[farthest_node]};
}

int main() {
    cin >> n;
    adj.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // First BFS from node 1 to find farthest node X
    int x = bfs(1).first;

    // Second BFS from X to find the diameter
    int diameter = bfs(x).second;

    cout << diameter << endl;
    return 0;
}
