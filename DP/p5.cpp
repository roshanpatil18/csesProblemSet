#include <bits/stdc++.h>

using namespace std;

using ll =long long;
ll mod=1000000007;

ll solve(ll n, vector<ll>&dp){

    if(n<0){
        return 1e9;
    }
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
     
    ll t=1e9;
    ll num=n;
    while(num>0){
        ll op=num%10;
       if(op>0){
        t=min( 1+solve(n-op,dp),t); 
       }
       
        
       num=num/10;
    }
    return dp[n]= t;
}
 
ll s(ll n){

    ll ans=0;

    while(n>0){
         ll op=n%10;
ans=max(op,ans);
n=n/10;
    }
    return ans;
}
signed main(){


    ll n;
  
    cin>>n;
    vector<ll>dp(n+1,-1);

    
//   cout<<solve(n,dp)<<endl;
     ll m=1e9;
     ll ans=0;
    while(m!=0){
        m=s(n);
        n=n-m;
        ans++;
    }
    cout<<ans-1<<endl;
}