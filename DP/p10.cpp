#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Base Case Initialization
    for (int i = 0; i <= n; i++) dp[i][m] = n - i; // Deletion cost
    for (int j = 0; j <= m; j++) dp[n][j] = m - j; // Insertion cost

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int del, rep, s = 1e9;

            if (s1[i] == s2[j]) {
                s = dp[i + 1][j + 1]; // No operation needed
            }

            del = 1 + min(dp[i][j + 1], dp[i + 1][j]); // Delete/Insert
            rep = 1 + dp[i + 1][j + 1]; // Replace

            dp[i][j] = min(s, min(del, rep));
        }
    }

    cout << dp[0][0] << endl;
}
