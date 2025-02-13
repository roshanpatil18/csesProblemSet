#include <bits/stdc++.h>
using namespace std;


const int mod = 1000000007;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
     
    vector<vector<long long>>dp(100001,vector<long long>(101,0));


     for(int i=1;i<=m;i++){
        dp[n][i]=1;
     }

       
     for(int i=n-1;i>=0;i--){
        for(int prev=0;prev<=m;prev++){
            if(prev!=0 && nums[i]!=0 && abs(nums[i]-prev)!=1 && abs(nums[i]-prev)!=0 ){
                continue;
            }
            long long total=0;
            if(nums[i]==0){
                for(int j=1;j<=m;j++){
                    if(prev==0 || abs(j - prev) == 1 ||abs(j - prev) == 0){
                        total+=dp[i+1][j];
                    }
                }
            }else{
                total+=dp[i+1][nums[i]];
            }
            dp[i][prev]=(total)%mod;
        }
     }
     cout<<dp[0][0];

      }




