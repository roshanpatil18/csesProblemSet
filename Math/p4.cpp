#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
vector<int> divisors_count(MAX, 0);

void precompute() {
    for (int i = 1; i < MAX; ++i) {
        for (int j = i; j < MAX; j += i) {
            divisors_count[j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // Fill divisor counts

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << divisors_count[x] << '\n';
    }

    return 0;
}
