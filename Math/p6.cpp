#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll sum_of_divisors(ll n) {
    ll ans = 0;
    for (ll i = 1; i <= n; ) {
        ll val = n / i;
        ll next_i = n / val + 1;

        ll count = next_i - i;
        ll total = (i + next_i - 1) % MOD;
        total = (total * count % MOD) * ((MOD + 1) / 2) % MOD; // Multiply by inverse of 2

        ans = (ans + val % MOD * total % MOD) % MOD;
        i = next_i;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << sum_of_divisors(n) << '\n';
    return 0;
}
