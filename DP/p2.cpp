#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod=1000000007;
   

int solve( vector<int>&num,int x,int sum,int i){


     if(i>=num.size()){
        if(sum==x){
            return 0;
        }
        return 1e9;
     }
    if(sum==x){
        return 0;
    }

    if(sum>x){
        return  1e9;
    }

    int inc=1+solve(num,x,sum+num[i],i);

    int exc=solve(num,x,sum,i+1);

    return min(inc,exc);
}

int main(){


    int n,x;
    cin>>n>>x;

      vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(x+1,1e9));

     

    for(int i=0;i<=n;i++){
        dp[i][x]=0;
    }


    for(int i=n-1;i>=0;i--){
        for(int j=x-1;j>=0;j--){

            int inc=1e9;
            if(j+num[i]<=x){
                inc=1+dp[i][num[i]+j];
            }
            int exc=dp[i+1][j];

            dp[i][j]=min(exc,inc);
        }

    }
    if(dp[0][0]==1e9){
        cout<<-1;
    }else{

        cout<<dp[0][0];
    }
    

   }