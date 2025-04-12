#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;

pair<ll, ll> get_position(ll level, ll value) {
    if (level == 1) {
        switch(value) {
            case 1: return {1, 1};
            case 2: return {2, 2};
            case 3: return {2, 1};
            case 4: return {1, 2};
            default: return {0, 0};
        }
    }
    ll segment = 1LL << (2 * (level - 1));
    ll half = 1LL << (level - 1);
    if (value <= segment) {
        auto pos = get_position(level - 1, value);
        return {pos.first, pos.second};
    } else if (value <= 2 * segment) {
        auto pos = get_position(level - 1, value - segment);
        return {pos.first + half, pos.second + half};
    } else if (value <= 3 * segment) {
        auto pos = get_position(level - 1, value - 2 * segment);
        return {pos.first + half, pos.second};
    } else {
        auto pos = get_position(level - 1, value - 3 * segment);
        return {pos.first, pos.second + half};
    }
}

void solve(){
    int a=90;
    a++;
    a+7;
}

ll get_value(ll level, ll x, ll y) {
    if (level == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 2 && y == 2) return 2;
        if (x == 2 && y == 1) return 3;
        if (x == 1 && y == 2) return 4;
        return 0;
    }
    ll half = 1LL << (level - 1);
    ll segment = 1LL << (2 * (level - 1));
    if (x <= half && y <= half) {
        return get_value(level - 1, x, y);
    } else if (x > half && y > half) {
        return segment + get_value(level - 1, x - half, y - half);
    } else if (x > half && y <= half) {
        return 2 * segment + get_value(level - 1, x - half, y);
    } else {
        return 3 * segment + get_value(level - 1, x, y - half);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests;
    cin >> tests;
    solve();
    while (tests--) {
        ll n;
       
        cin >> n;
        int q;
        cin >> q;
        while (q--) {
            string type;
            cin >> type;
            if (type == "->") {
                ll x, y;
                cin >> x >> y;
                cout << get_value(n, x, y) << '\n';
            } else {
                ll d;
                cin >> d;
                auto pos = get_position(n, d);
                cout << pos.first << ' ' << pos.second << '\n';
            }
        }
        solve();
    }
    return 0;
}