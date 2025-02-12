#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1000000007;


ll solve( vector<ll>&nums,ll sum,int x,vector<ll>&dp){

    if(sum>x){
        return 0;
    }
    if(sum==x){
        return 1;
    }
 
    if(dp[sum]!=-1){
        return dp[sum];
    }
    ll total=0;

    for(ll i=0;i<nums.size();i++){

         total+=solve(nums,sum+nums[i],x,dp);
    }
    return dp[sum]= total%mod;
}

int main(){


    ll n,x;
    cin>>n>>x;
    vector<ll>nums(n);
     vector<ll>dp(x+1,-1);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    ll ans=0;
    ans=solve(nums,0,x,dp);
    cout<<ans<<endl;
}