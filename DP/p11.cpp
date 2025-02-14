#include <bits/stdc++.h>
using namespace std;




int solve(int a,int b){


    if(a==b){
        return 0;
    }
      
    int x=1e9;
    int y=1e9;
    for(int i=1;i<a;i++){
        x=min(x,(1+(solve(a-i,b)+solve(i,b))));
    }
    for(int i=1;i<b;i++){
        y=min(y,(1+(solve(a,b-i)+solve(a,i))));
    }

return min(x,y);


}
int main(){



    int a,b;
    cin>>a>>b;

     vector<vector<int>>dp(a+1,vector<int>(b+1,0));

 

     for(int  i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            int x=1e9;
            int y=1e9;
            for(int k=1;k<i;k++){
               x=min(x,(1+(dp[i-k][j]+dp[k][j])));
            }
            for(int k=1;k<j;k++){
                y=min(y,(1+(dp[i][j-k]+dp[i][k])));
            }
            dp[i][j]=min(x,y);
        }

     }
     cout<<dp[a][b];
}