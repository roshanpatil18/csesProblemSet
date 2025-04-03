#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> temp;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
        temp.push_back(a);
    }

    long long h = *max_element(temp.begin(), temp.end());
    long long k = sum - h;
    long long l=k;
   

    if (l < h) {
        cout << (2 * h) << endl;
        return 0;
    }

    cout << sum << endl;
    return 0;
}
