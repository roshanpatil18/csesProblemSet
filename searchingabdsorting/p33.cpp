

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){


    int n,a,b;

    cin>>n>>a>>b;

    vector<ll>temp(n);

    for(int i=0;i<n;i++){
          cin>>temp[i];
    }



    vector<ll>pre(n+1,0);

    for(int i=1;i<=n;i++){
            
        pre[i]=pre[i-1]+temp[i-1];
    }

    deque<int>dq;
    ll ans=LLONG_MAX;

    for(int i=0;i<=n;i++){

        int add=i-a;
        if(add>=0){

            while(!dq.empty() && pre[dq.back()]>=pre[add]){
                dq.pop_back();
            }
            dq.push_back(add);
        }

        int rem=i-b-1;

        while(rem>=0 && !dq.empty()){
            dq.pop_back();
            rem--;
        }

        if(i>=0 && !dq.empty()){
             ll best=dq.front();
             ans=max(ans,pre[i]-best);
        }



    }
    cout<<ans;
}