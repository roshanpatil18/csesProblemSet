#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<char>> temp(n, vector<char>(n));
    vector<vector<int>> arr(n, vector<int>(n, 0));

    // Read forest map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp[i][j];
            if (temp[i][j] == '*') {
                arr[i][j] = 1;
            }
        }
    }

    // Compute 2D prefix sums
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            arr[i][j] += arr[i - 1][j];
        }
    }

    // Answer queries
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--, y2--, x2--;

        int res = arr[y2][x2];
        if (y1 > 0) res -= arr[y1 - 1][x2];
        if (x1 > 0) res -= arr[y2][x1 - 1];
        if (y1 > 0 && x1 > 0) res += arr[y1 - 1][x1 - 1];

        cout << res << '\n';
    }

    return 0;
}
