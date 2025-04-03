#include <bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin>>n;
    vector<pair<int,int>>temp;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        temp.push_back({a,b});
    }

    sort(temp.begin(),temp.end());

    long long  ans=0;
    long long  c=0;

    for(int i=0;i<n;i++){
        c+=temp[i].first;
        ans+=temp[i].second-c;
    }

cout<<ans;



}