#include <bits/stdc++.h>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Directions: up, down, left, right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// Structure to represent a cell
struct Cell {
    int row, col;
    int g, h; // g = cost from start, h = heuristic to goal
    Cell* parent;

    Cell(int r, int c, int gCost, int hCost, Cell* p = nullptr) {
        row = r;
        col = c;
        g = gCost;
        h = hCost;
        parent = p;
    }

    int f() const {
        return g + h;
    }
};

// Compare cells for priority queue
struct Compare {
    bool operator()(Cell* a, Cell* b) {
        return a->f() > b->f();
    }
};

// Manhattan distance
int heuristic(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

// Check if cell is within grid and not a wall
bool isValid(int r, int c, const vector<vector<int>>& grid) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c] == 0;
}

// Reconstruct and print path
void printPath(Cell* node) {
    vector<pair<int, int>> path;
    while (node) {
        path.push_back({node->row, node->col});
        node = node->parent;
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (auto cell : path) {
        cout << "(" << cell.first << "," << cell.second << ") ";
    }
    cout << endl;
}

// A* Algorithm
void aStar(const vector<vector<int>>& grid, int startRow, int startCol, int endRow, int endCol) {
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    priority_queue<Cell*, vector<Cell*>, Compare> open;

    Cell* start = new Cell(startRow, startCol, 0, heuristic(startRow, startCol, endRow, endCol));
    open.push(start);

    while (!open.empty()) {
        Cell* current = open.top();
        open.pop();

        int r = current->row;
        int c = current->col;

        if (visited[r][c]) continue;
        visited[r][c] = true;

        // Reached goal
        if (r == endRow && c == endCol) {
            printPath(current);
            return;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc, grid) && !visited[nr][nc]) {
                int newG = current->g + 1;
                int newH = heuristic(nr, nc, endRow, endCol);
                Cell* neighbor = new Cell(nr, nc, newG, newH, current);
                open.push(neighbor);
            }
        }
    }

    cout << "No path found!" << endl;
}

int main() {
    // 0 = free, 1 = wall
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    aStar(grid, 0, 0, 4, 4);

    return 0;
}
