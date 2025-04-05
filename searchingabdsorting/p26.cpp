#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    unordered_map<long long, long long> mp;
    long long sum = 0, ans = 0;

    mp[0] = 1; // Base case for subarrays that start from index 0

    for (int i = 0; i < n; i++) {
        sum += num[i];

        long long k = sum - t;
        if (mp.find(k) != mp.end()) {
            ans +=mp[k] ;// Count all previous occurrences of (sum - t)
        }

        mp[sum]++;  // Store sum frequency
    }

    cout << ans << endl;
    return 0;
}
