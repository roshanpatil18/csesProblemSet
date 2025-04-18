#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxin = 2e5 + 5;
vector<ll> tree(4 * maxin);
vector<ll> arr(maxin);

void build(ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    ll mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    if (l > end || r < start)
        return LLONG_MAX;

    if (l <= start && end <= r)
        return tree[node];

    ll mid = (start + end) / 2;
    ll left = query(node * 2, start, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, end, l, r);
    return  min(left  ,right);
}

void update(ll node, ll start, ll end, ll in, ll val) {
    if (start == end) {
        tree[node] = val;
        arr[in] = val;
        return;
    }

    ll mid = (start + end) / 2;
    if (in <= mid)
        update(node * 2, start, mid, in, val);
    else
        update(node * 2 + 1, mid + 1, end, in, val);

    tree[node] = min(tree[node * 2] , tree[node * 2 + 1]);
}

int main() {
   

    ll n, q;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            ll a, b;
            cin >> a >> b;
            update(1, 1, n, a, b);
        } else {
            ll a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << '\n';
        }
    }
}
