#include <bits/stdc++.h>
using namespace std;
using ll=long long ;


 ll solve(vector<int>num,int k,int i,int j,   vector<vector<ll>>&dp){
          
    if(i>j){
        return 0;
    }


    if(dp[i][j]!=INT_MIN){
        return dp[i][j];
    }
    int l=i+j;
    
    if(l%2==k){

     return dp[i][j]= max(num[i]+solve(num,k,i+1,j,dp),num[j]+solve(num,k,i,j-1,dp));
    }

        return dp[i][j]= min(solve(num,k,i+1,j,dp),solve(num,k,i,j-1,dp));
    





 }
int main(){

   

    int n ;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
 int k=0;
    if(n%2==0){
        k=1;
    }else{
        k=0;
    }



    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));

 
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
           if(i>j) continue;
           
           if(i==j){
            int l=i+j;
            if(l%2==k){
                dp[i][j]=num[i];
            }else{
                dp[i][j]=0;
            }
            continue;
           }

         int l=i+j;
         if(l%2==k){
            dp[i][j]=max(num[i]+dp[i+1][j],num[j]+dp[i][j-1]);
         }else{
            dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
         
        }
        } 
    }

   
    cout<<dp[0][n-1];


}