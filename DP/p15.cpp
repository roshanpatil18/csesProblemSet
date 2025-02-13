#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ans;
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        auto it = ans.lower_bound(nums[i]); 

        if (it != ans.end()) {
            ans.erase(it); 
        }
        ans.insert(nums[i]);
    }

    cout << ans.size();
}
