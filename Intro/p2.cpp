#include <bits/stdc++.h>
using namespace std;



int main(){


    int n;
    cin>>n;

    vector<int>num(n-1);
    vector<int>temp(n,0);
    for(int i=0;i<n-1;i++){
        cin>>num[i];
    }

    for(auto it:num){
        temp[it-1]--;
    }

      int ans;
    for(int i=0;i<n;i++){
       if(temp[i]==0){
        ans=i+1;
       }
    }
    cout<<ans;
}