#include <bits/stdc++.h>

using namespace std;


vector<int>ans;


void dfs(int n, vector<vector<int>>&temp){

     for(auto it:temp[n]){
        dfs(it ,temp);
        ans[n-1]+=ans[it-1]+1;

     }
}
int main(){



    int n;
    cin>>n;
  vector<vector<int>>temp(n+1);

    for(int i=2;i<=n;i++){
        int a;
        cin>>a;

        temp[a].push_back(i);
    }

    ans.resize(n,0);
    dfs(1,temp);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}