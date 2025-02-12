#include <bits/stdc++.h>

using namespace std;

using ll =long long;
ll mod=1000000007;

ll solve(vector<vector<char>>&nums,ll i,ll j, vector<vector<ll>>&dp){

    int n=nums.size();
    if(i>=n || i<0 || j>=n || j<0 || nums[i][j]=='*'){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){

        return dp[i][j];
    }

    ll t=0;

    t+=solve(nums,i+1,j,dp);
    t+=solve(nums,i,j+1,dp);
    return dp[i][j]= t%mod;
}

signed main(){
 
    ll n;
    cin>>n;
      char a;  
      vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
    vector<vector<char>>nums(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin>>nums[i][j];
        }
    }
  ll ans=0;
   ans=solve(nums,0,0,dp);
   cout<<ans<<endl;



}
