#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

vector<int> r;           // ways to reach
vector<ll> mini;         // min flights
vector<ll> maxi;         // max flights
vector<ll> disi;         // min distance

void solve(vector<vector<pair<ll, ll>>> &temp) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;


    disi[1] = 0;
    r[1] = 1;
    mini[1] = 0;
    maxi[1] = 0;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, no] = pq.top(); pq.pop();

        if (d > disi[no]) continue;

        for (auto [k, dis] : temp[no]) {
            if (disi[k] > d + dis) {
                disi[k] = d + dis;
                mini[k] = mini[no] + 1;
                maxi[k] = maxi[no] + 1;
                r[k] = r[no];
                pq.push({disi[k], k});
            } else if (disi[k] == d + dis) {
                mini[k] = min(mini[k], mini[no] + 1);
                maxi[k] = max(maxi[k], maxi[no] + 1);
                r[k] = (r[k] + r[no]) % MOD;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> temp(n + 1);
    disi.assign(n + 1, INF);
    mini.assign(n + 1, 1e9);
    maxi.assign(n + 1, 0);
    r.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        temp[a].push_back({b, c});
    }

    solve(temp);
    cout << disi[n] << " " << r[n] << " " << mini[n] << " " << maxi[n] << "\n";
}
