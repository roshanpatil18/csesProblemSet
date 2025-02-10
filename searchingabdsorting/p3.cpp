#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long m;
    cin >> m;

    vector<long long> h(n);
    vector<long long> t(m);

    for (long long i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (long long i = 0; i < m; i++) {
        cin >> t[i];
    }

    vector<long long> ans;
    multiset<long long> st;

    for (long long i = 0; i < h.size(); i++) {
        st.insert(h[i]);
    }

    for (long long i = 0; i < t.size(); i++) {
        auto it = st.upper_bound(t[i]);
        if (it == st.begin()) {
            ans.push_back(-1);
        } else {
            --it;
            ans.push_back(*it);
            st.erase(it);
        }
    }

    for (long long i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
