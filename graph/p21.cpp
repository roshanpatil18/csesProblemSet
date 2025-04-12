#include <bits/stdc++.h>

using namespace std;



int main(){

    int n,m;
    cin>>n>>m;


    vector<int>temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
        --temp[i];
    }

    int LOG=30;
    
    vector<vector<int>>up(31,vector<int>(n,-1));

    for(int i=0;i<n;i++){
        up[0][i]=temp[i];
    }

    for(int i=1;i<30;i++){
        for(int j=0;j<n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }


     while (m--) {
        int a;
        long long b; // FIXED: should be long long
        cin >> a >> b;
        a--;

        for (int i = 0; i <= 30; i++) {
            if (b & (1LL << i)) { // FIXED: 1LL to avoid overflow
                a = up[i][a];
            }
        }

        cout << a + 1 << '\n'; // convert back to 1-base
    }


}