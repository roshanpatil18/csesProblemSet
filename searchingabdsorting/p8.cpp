#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end()); 

    long long totalsum = 0;
    for (int i = 0; i < n; i++) {
        if (coins[i] > totalsum + 1) {
            cout << totalsum + 1;
            return 0;
        }
        totalsum += coins[i];
    }

    
    cout << totalsum + 1;
    return 0;
}
