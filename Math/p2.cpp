

#include <bits/stdc++.h>
using namespace  std;
using ll=long long ;
const ll MOD = 1e9 + 7;

ll solve(ll a,ll b){


    ll res=1;
    if(a==0 && b==0){
        return 1;
    }
   

    a=a%MOD;

    while(b>0){

        if(b%2!=0){
            res=res*a%MOD;
        }
        a=a*a%MOD;
        b=b/2;
    }
    return res;
}
int main(){



    int n;
    cin>>n;

    while(n--){
      
        ll a,b;
        cin>>a>>b;

        cout<<solve(a,b)<<endl;


    }
}