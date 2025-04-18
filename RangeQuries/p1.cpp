#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> temp(n + 1);  // use long long for prefix sum array

    for (int i = 1; i <= n; i++) {
        cin >> temp[i];
    }

    // Compute prefix sums
    for (int i = 1; i <= n; i++) {
        temp[i] += temp[i - 1];
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        cout << temp[b] - temp[a - 1] << '\n';
    }

    return 0;
}
