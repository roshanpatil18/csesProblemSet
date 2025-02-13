#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;


 int solve(vector<int>&nums,int i,int x,int s,   vector<vector<int>>&dp){

    if(s==x){
        return 1;
    }
    if(i==nums.size()){
        return 0;
    }
    if(s>x){
        return 0;
    }
    if(dp[i][s]!=-1){
        return dp[i][s];
    }

    int t=solve(nums,i,x,s+nums[i],dp);

    int l=solve(nums,i+1,x,s,dp);

    return  dp[i][s]= l+t;
 }
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    vector<vector<int>> dp(n+1 ,vector<int>(x+1, 0)); 
      

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }



    for(int i=0;i<n;i++){
        dp[i][x]=1;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=x-1;j>=0;j--){
            int t=0;
            if(j+nums[i]<=x){
              t=dp[i][j+nums[i]];
            }
            int l=dp[i+1][j];

            dp[i][j]=(l+t)%mod;
        }
    }
   cout<<dp[0][0];

}
