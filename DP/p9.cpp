#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int MAXN = 1000001;
long long dp[MAXN][2]; 

// Recursive memoized function
long long solve(int n, int state) {
    if (n == 1)
        return 1;  // Base case: dp[1][0] = dp[1][1] = 1
    if (dp[n][state] != -1)
        return dp[n][state];

    long long ans;
    if (state == 0) { // both below tile are free
        ans = ( (4LL * solve(n - 1, 0)) % mod + solve(n - 1, 1) ) % mod;
    } else { // state == 1, both below tile are connected
        ans = ( solve(n - 1, 0) + (2LL * solve(n - 1, 1)) % mod ) % mod;
    }
    return dp[n][state] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    // Initialize dp table with -1 (uncomputed state)
    memset(dp, -1, sizeof(dp));
    
    while(t--){
        int n;
        cin >> n;
        // Total towers = dp[n][0] + dp[n][1]
        cout << (solve(n, 0) + solve(n, 1)) % mod << "\n";
    }
    return 0;
}
