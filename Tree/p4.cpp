#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj;

vector<int> bfs(int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
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

    // Find one endpoint of the diameter
    vector<int> dist1 = bfs(1);
    int far1 = 1;
    for (int i = 1; i <= n; ++i) {
        if (dist1[i] > dist1[far1]) far1 = i;
    }

    // BFS from far1 to find the other endpoint
    vector<int> dist_from_far1 = bfs(far1);
    int far2 = far1;
    for (int i = 1; i <= n; ++i) {
        if (dist_from_far1[i] > dist_from_far1[far2]) far2 = i;
    }

    // BFS from far2
    vector<int> dist_from_far2 = bfs(far2);

    // For each node, max(dist from far1, dist from far2)
    for (int i = 1; i <= n; ++i) {
        cout << max(dist_from_far1[i], dist_from_far2[i]) << " ";
    }
    cout << endl;
    return 0;
}
