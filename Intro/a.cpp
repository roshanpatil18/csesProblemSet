#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> temp(n);
        vector<int> temp2(n);
        for (int i = 0; i < n; i++) {
            cin >> temp[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> temp2[i];
        }
        
        int last_sort_pos = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (temp[i] == 2 || temp[i] == 3) {
                last_sort_pos = i;
                break;
            }
        }
        
        if (last_sort_pos != -1) {
            if (temp[last_sort_pos] == 2) {
                sort(temp2.begin(), temp2.end());
            } else {
                sort(temp2.begin(), temp2.end(), greater<int>());
            }
            int rev_count = 0;
            for (int i = last_sort_pos + 1; i < n; i++) {
                if (temp[i] == 1) {
                    rev_count++;
                }
            }
            if (rev_count % 2 == 1) {
                reverse(temp2.begin(), temp2.end());
            }
        } else {
            int rev_count = 0;
            for (int i = 0; i < n; i++) {
                if (temp[i] == 1) {
                    rev_count++;
                }
            }
            if (rev_count % 2 == 1) {
                reverse(temp2.begin(), temp2.end());
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << temp2[i] << " ";
        }
        cout << "\n";
    }
}