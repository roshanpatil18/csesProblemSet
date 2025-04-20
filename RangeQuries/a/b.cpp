#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int px = 0, py = 0;
        for(int i = 0; i < n; i++){
            long long x, y;
            cin >> x >> y;
            px ^= (x & 1);
            py ^= (y & 1);
        }
        // Output any (s,t) with s%2 = px, t%2 = py
        // e.g. (px, py) itself is within [-1e9,1e9]
        cout << px << " " << py << "\n";
    }
    return 0;
}
