#include <bits/stdc++.h>
using namespace std;

int main() {

       

    int n;
    cin>>n;

    vector<pair<int,int>>temp;

    for(int i=1;i<=n;i++){
            int a;
            cin>>a;
           temp.push_back({a,i});
    }

sort(temp.begin(),temp.end());


int ans=1;

for(int i=1;i<n;i++){
     
    if(temp[i].second<temp[i-1].second){
        ans++;
    }



}
cout<<ans;


}