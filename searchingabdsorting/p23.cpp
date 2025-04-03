#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> temp;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        temp.push_back({a, i});
    }

    sort(temp.begin(), temp.end()); // Sort based on values

    vector<int> ans;

    for (int i = 0; i < n - 2; i++) { // `i` should start from 0
        int l = i + 1, r = n - 1; // Two-pointer approach

        while (l < r) {
            int sum = temp[i].first + temp[l].first + temp[r].first;
            
            if (sum == t) {
                ans = {temp[i].second, temp[l].second, temp[r].second};
                sort(ans.begin(), ans.end());
                for (int x : ans) cout << x << " ";
                cout << endl;
                return 0; // Exit immediately after finding the answer
            } 
            else if (sum > t) {
                r--;
            } 
            else {
                l++;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
