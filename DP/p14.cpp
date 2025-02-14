#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

   
 int solve(int i,int s,int sum,int n){

    if(s>sum){
        return 0;
    }

    if(i==n+1){
        if(sum==s){
            return 1;
        }else{
            return 0;
        }
    }

    int inc=0;
    int exc=0;

    inc+=solve(i+1,s+i,sum,n);
    exc+=solve(i+1,s,sum,n);

    return (inc+exc)%mod;
 }
int main(){


    int n;
    cin>>n;

    int total = (n * (n + 1)) / 2;

    if(total%2!=0){
        cout<<0<<endl;
           
    }else{

        int sum=total/2;

        


        vector<vector<int>>dp(n+2,vector<int>(sum+1,0));
         
        dp[n+1][sum]=1;


        for(int i=n;i>=0;i--){
            for(int j=sum;j>=0;j--){
                int inc=0;
                int exc=0;
              
                if(i+j<=sum){
                    inc=dp[i+1][i+j];
                }
                
                exc=dp[i+1][j];

                dp[i][j] = ( (long long)inc + exc ) % mod;
            }
        }
    
        // Each valid partition is counted twice, so we divide the result by 2.
        // Since mod is prime, we use the modular inverse of 2 modulo mod.
        long long inv2 = 500000004;  // because 2^(mod-2) mod mod equals 500000004 for mod = 10^9+7
    
        // dp[1][0] holds the number of ways to form a subset of {1,...,n} with sum equal to sum.
        cout << ( (long long)dp[1][0] * inv2 ) % mod << "\n";
    
    }



   



}