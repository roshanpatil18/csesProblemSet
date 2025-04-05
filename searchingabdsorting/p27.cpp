#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    long long sum = 0;
    unordered_map<int, int> mp;

    mp[0] = 1; // Base case for prefix sum divisible by `n`
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        sum += num[i];

        int rem = ((sum % n) + n) % n;  // Ensure non-negative remainder

        if (mp.find(rem) != mp.end()) {
            ans += mp[rem];  // Count valid subarrays
        }

        mp[sum]++;  // Store remainder frequency
    }

    cout << ans << endl;
    return 0;
}
