#include <bits/stdc++.h>
using namespace std;

bool isposs(int i, int j, vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#');
}

// Monster BFS: compute the earliest time a monster reaches every cell.
void solve(vector<vector<char>> &grid, queue<pair<int, pair<int,int>>> &q, vector<vector<int>> &g) {
    int n = grid.size(), m = grid[0].size();
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        
        // If we already have an equal or better time, skip.
        if(g[a][b] <= c) continue;
        g[a][b] = c;
        for(int k = 0; k < 4; k++){
            int ni = a + dx[k], nj = b + dy[k];
            if(isposs(ni, nj, grid)){
                q.push({ni, {nj, c + 1}});
            }
        }
    }
}

// Person BFS: try to escape while arriving strictly before any monster.
bool bfs(vector<vector<int>> &g, vector<vector<char>> &grid, int sx, int sy,
         vector<vector<pair<int,int>>> &par, vector<vector<char>> &moveDir) {
    int n = grid.size(), m = grid[0].size();
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int,int>> qu;
    
    dist[sx][sy] = 0;
    qu.push({sx, sy});
    
    // Directions: Down, Right, Up, Left.
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    char d[] = {'D', 'R', 'U', 'L'};
    
    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        int x = cur.first, y = cur.second;
        // If on boundary, we have found an exit.
        if(x == 0 || y == 0 || x == n - 1 || y == m - 1){
            string path;
            int cx = x, cy = y;
            // Reconstruct the path using parent pointers.
            while(!(cx == sx && cy == sy)){
                path.push_back(moveDir[cx][cy]);
                auto p = par[cx][cy];
                cx = p.first; cy = p.second;
            }
            reverse(path.begin(), path.end());
            cout << "YES" << "\n" << path.size() << "\n" << path;
            return true;
        }
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(grid[nx][ny] == '#') continue;
            if(dist[nx][ny] <= dist[x][y] + 1) continue;
            // Only move if you reach before a monster.
            if(dist[x][y] + 1 >= g[nx][ny]) continue;
            dist[nx][ny] = dist[x][y] + 1;
            par[nx][ny] = {x, y};
            moveDir[nx][ny] = d[k];
            qu.push({nx, ny});
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                sx = i;
                sy = j;
            }
        }
    }
    
    // g stores the earliest time a monster reaches each cell.
    const int INF = 1e9;
    vector<vector<int>> g(n, vector<int>(m, INF));
    queue<pair<int, pair<int,int>>> mq;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                mq.push({i, {j, 0}});
            }
        }
    }
    solve(grid, mq, g);
    
    // For path reconstruction.
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m, ' '));
    
    if(!bfs(g, grid, sx, sy, par, moveDir)){
        cout << "NO";
    }
    
    return 0;
}
