#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<int> salaries(n + 1);
    multiset<int> ms;

    for (int i = 1; i <= n; ++i) {
        cin >> salaries[i];
        ms.insert(salaries[i]);
    }

    while (q--) {
        char op;
        cin >> op;

        if (op == '!') {
            int k, x;
            cin >> k >> x;
            ms.erase(ms.find(salaries[k])); // remove old salary
            salaries[k] = x;
            ms.insert(x); // insert new salary
        } else if (op == '?') {
            int a, b;
            cin >> a >> b;
            auto low = ms.lower_bound(a);
            auto high = ms.upper_bound(b);
            cout << distance(low, high) << '\n';
        }
    }

    return 0;
}
