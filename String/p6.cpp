#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    string t = "^";
    for (char c : s) {
        t += '#' + string(1, c);
    }
    t += "#$";

    int m = t.length();
    vector<int> p(m, 0);

    int c = 0, r = 0;

    for (int i = 1; i < m - 1; i++) {
        int mirr = 2 * c - i;

        if (i < r)
            p[i] = min(r - i, p[mirr]);

        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;

        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }

    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < m - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    cout << s.substr(start, maxLen);
}
