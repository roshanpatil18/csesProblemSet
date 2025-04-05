#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;

    vector<pair<int, int>> temp;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        temp.push_back({a, i});
    }

    sort(temp.begin(), temp.end()); // Sort based on values

    vector<int> ans;

    for (int i = 0; i < n - 3; i++) {  // First number
        for (int k = i + 1; k < n - 2; k++) {  // Second number
            int l = k + 1, r = n - 1; // Third and fourth numbers (Two-pointer approach)
            
            while (l < r) {
                long long sum = temp[i].first + temp[k].first + temp[l].first + temp[r].first;

                if (sum == t) {
                    ans = {temp[i].second, temp[k].second, temp[l].second, temp[r].second};
                    sort(ans.begin(), ans.end());
                    for (int x : ans) cout << x << " ";
                    cout << endl;
                    return 0;  // Exit immediately after finding the answer
                } 
                else if (sum > t) {
                    r--;  // Reduce sum by moving `r` left
                } 
                else {
                    l++;  // Increase sum by moving `l` right
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
