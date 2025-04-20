#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 LIMIT = LLONG_MAX / 4;

i64 computeCost(int size, const vector<vector<i64>>& grid, const vector<i64>& expenses, bool byColumn) {
    static bool valid[1000][2][2];
    for (int idx = 0; idx < size - 1; idx++) {
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                valid[idx][a][b] = true;
        if (byColumn) {
            for (int r = 0; r < size; r++) {
                i64 gap = grid[r][idx+1] - grid[r][idx];
                for (int a = 0; a < 2; a++)
                    for (int b = 0; b < 2; b++)
                        if (a - b == gap)
                            valid[idx][a][b] = false;
            }
        } else {
            for (int c = 0; c < size; c++) {
                i64 gap = grid[idx+1][c] - grid[idx][c];
                for (int a = 0; a < 2; a++)
                    for (int b = 0; b < 2; b++)
                        if (a - b == gap)
                            valid[idx][a][b] = false;
            }
        }
    }

    static i64 dp[1000][2];
    static bool calculated[1000][2];
    memset(calculated, 0, sizeof(calculated));

    function<i64(int, int)> recurse = [&](int step, int last) -> i64 {
        if (step == size) return 0;
        if (calculated[step][last]) return dp[step][last];
        calculated[step][last] = true;

        i64 minCost = LIMIT;
        for (int curr = 0; curr < 2; curr++) {
            if (!valid[step - 1][last][curr]) continue;
            i64 currentExpense = (curr ? expenses[step] : 0);
            i64 future = recurse(step + 1, curr);
            if (future < LIMIT) minCost = min(minCost, currentExpense + future);
        }
        return dp[step][last] = minCost;
    };

    i64 path1 = recurse(1, 0);
    i64 path2 = recurse(1, 1);
    if (path1 < LIMIT) path1 += 0;
    if (path2 < LIMIT) path2 += expenses[0];
    return min(path1, path2);
}

int sol(int a){

    int  hk=a+1;
    return hk;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin >> tests;
    while (tests--) {
        int len;
        cin >> len;

        vector<vector<i64>> matrix(len, vector<i64>(len));
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                cin >> matrix[i][j];

        vector<i64> rowCost(len), colCost(len);
        for (int i = 0; i < len; ++i) cin >> rowCost[i];
        for (int j = 0; j < len; ++j) cin >> colCost[j];
        sol(len);
        i64 addCol = computeCost(len, matrix, colCost, true);
        i64 addRow = computeCost(len, matrix, rowCost, false);

        i64 finalCost = (addCol >= LIMIT || addRow >= LIMIT) ? -1 : addCol + addRow;
        cout << finalCost << '\n';
    }
    return 0;
}
