#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> Z(n);
    Z[0] = n;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);
        else
            Z[i] = 0;
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if(i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    auto Z = z_function(s);
    vector<int> periods;
    // check all k from 1..n-1
    for(int k = 1; k < n; k++){
        if(Z[k] >= n - k)
            periods.push_back(k);
    }
    // n is always a trivial period
    periods.push_back(n);

    // output in increasing order
    for(int i = 0; i < (int)periods.size(); i++){
        if(i) cout << ' ';
        cout << periods[i];
    }
    cout << '\n';
    return 0;
}
