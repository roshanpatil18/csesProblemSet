#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1), prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] ^ arr[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (prefix[b] ^ prefix[a - 1]) << '\n';
    }

    return 0;
}
