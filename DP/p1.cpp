#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1000000007;


ll solve(ll n ,ll s,vector<ll>&dp){

    if(s>n){
        return 0;
    }
    if(s==n){
        return 1;
    }
   if(dp[s]!=-1){
    return dp[s];
   }
 ll t=0;
    for(int i=1;i<=6;i++){
     t+=solve(n,s+i,dp);
    }
    return dp[s]=t%mod;
}

signed main(){
     

ll n;
cin>>n;
ll sum=0;
vector<ll>dp(n+2,-1);

 sum=solve(n,0,dp);
cout<<sum<<endl;


        
}