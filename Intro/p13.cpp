#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grey = {"0", "1"};

    for (int i = 2; i <= n; i++) {
        int s = grey.size();
        
        // Append reversed list with '1' prefix
        for (int j = s - 1; j >= 0; j--) {
            grey.push_back("1" + grey[j]);
        }

        // Prefix '0' to first half
        for (int j = 0; j < s; j++) {
            grey[j] = "0" + grey[j];
        }
    }

    for (auto it : grey) {
        cout << it << endl;
    }
}
