#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll MOD_MINUS_1 = MOD - 1; // Used for reducing exponent

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll solve(ll a, ll b, ll c) {
    if (a == 0 && b == 0 && c == 0) return 0; // 0^0 = 1
   

    ll exponent = binpow(b, c, MOD_MINUS_1); // b^c mod (MOD-1)
    return binpow(a, exponent, MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << '\n';
    }

    return 0;
}
