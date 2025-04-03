#include <bits/stdc++.h>
using namespace std;
long long ans=INT_MAX;
long long total=0;

void solve(vector<int>num,int i,long long t){
    
    if(i==num.size()){
        long   long rem=total-t;
        long long ab=abs(t-rem);
        ans=min(ans,ab);
        return  ;
    }



    solve(num,i+1,t+num[i]);
    solve(num,i+1,t);

}



int main(){

    int n;
    cin>>n;
    vector<int>num(n);

    for(int i=0;i<n;i++){
        cin>>num[i];
        total+=num[i];
    }

    solve(num,0,0);
    cout<< ans;
}