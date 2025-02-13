#include <bits/stdc++.h>
 
using namespace std;
 
using ll =long long;
ll mod=1000000007;
 
 
ll solve( vector<ll>&price , vector<ll>&book ,ll x,ll i,ll p , vector<vector<ll>>&dp){
 
   
    if(i==price.size() ){
       return 0;
    }
 
    if(dp[i][p]!=-1){return dp[i][p];}
 
      ll t=-1e9;   
    
     if(p+price[i]<=x){
       t= max(t, book[i]+solve(price,book,x,i+1,p+price[i],dp));
     }
 
 
     ll l = solve(price,book,x,i+1,p,dp);
 
     return dp[i][p]= max(t,l);
 
 
 
}
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> book(n);

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> book[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(x + 2, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = x; j >= 0; j--) {
            int t = INT_MIN;
            int l = dp[i + 1][j];

            if (j + price[i] <= x) {
                t = max(t, book[i] + dp[i + 1][j + price[i]]);
            }

            dp[i][j] = max(t, l);
        }
    }

    cout << dp[0][0];

    return 0;
}