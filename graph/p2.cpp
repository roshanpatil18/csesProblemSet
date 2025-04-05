#include <bits/stdc++.h>
using namespace std;

vector<char> ans;
vector<vector<char>> g;
vector<vector<int>> vis;

bool poss(int x, int y, const vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (grid[x][y] == '#' || vis[x][y]) return false;

    return true;
}

bool bfs(int i, int j, const vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (grid[a][b] == 'B') {
            while (true) {
                ans.push_back(g[a][b]);

                if (ans.back() == 'L') b++;
                else if (ans.back() == 'R') b--;
                else if (ans.back() == 'U') a++;
                else if (ans.back() == 'D') a--;

                if (a == i && b == j) break;
            }
            return true;
        }

        if (poss(a, b - 1, grid)) {
            g[a][b - 1] = 'L';
            q.push({a, b - 1});
            vis[a][b - 1] = 1;
        }
        if (poss(a - 1, b, grid)) {
            g[a - 1][b] = 'U';
            q.push({a - 1, b});
            vis[a - 1][b] = 1;
        }
        if (poss(a + 1, b, grid)) {
            g[a + 1][b] = 'D';
            q.push({a + 1, b});
            vis[a + 1][b] = 1;
        }
        if (poss(a, b + 1, grid)) {
            g[a][b + 1] = 'R';
            q.push({a, b + 1});
            vis[a][b + 1] = 1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    g.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m, 0));

    bool found = false;

    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (grid[i][j] == 'A') {
                found = bfs(i, j, grid);
            }
        }
    }

    if (found) {
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (char c : ans) cout << c;
    } else {
        cout << "NO";
    }

    return 0;
}
