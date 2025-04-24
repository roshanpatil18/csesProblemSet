#include <iostream>
using namespace std;

int find_kth(int n, int k) {
    if (n == 1) return 1;
    int mid = (n + 1) / 2;
    if (k <= mid) {
        int ans = 2 * k;
        return ans ;
    } else {
        int tmp = find_kth(n / 2, k - mid);
        if (n % 2 == 0)
            return 2 * tmp - 1;
        else
            return 2 * tmp + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << find_kth(n, k) << '\n';
    }

    return 0;
}