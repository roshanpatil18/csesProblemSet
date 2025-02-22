#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1000000007;
   
set<int>st;


void solve(  vector<int>nums,int i,int sum){

    if(i==nums.size()){
          st.insert(sum);
          return;
    }

    solve(nums,i+1,sum+nums[i]);
    solve(nums,i+1,sum);
}
int main(){

    int n;

    cin>>n;
    vector<int>nums(n);
    ll total=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        total+=nums[i];
    }

    
     
    vector<vector<bool>>dp(n+1,vector<bool>(total+1,0));
     

    dp[n][0]=1;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=total;j++){
           

            if(dp[i+1][j]){
                dp[i][j]=1;
            

            if(j+nums[i]<=total){
                dp[i][j+nums[i]]=true;
            }
        } 
        }
    }




vector<int>ans;
    for(int i=0;i<=total;i++){
           if(dp[0][i]){
            ans.push_back(i);
           }

    }

    cout<<ans.size()-1<<endl;
    for(auto it:ans){
        if(it==0){
            continue;
        }
        cout<<it<<" ";
    }
}