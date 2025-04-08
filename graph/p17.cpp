#include <bits/stdc++.h>
using namespace std;


int main(){

       

    int n,m;
    cin>>n>>m;

    vector<vector<int>>temp(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        temp[a].push_back(b);
    }

    vector<int>par(n+1,-1);
queue<int>q;
     q.push(1);

     while(!q.empty()){

        int k=q.front();
        q.pop();

        for(auto it:temp[k]){
            par[it]=k;
            q.push(it);
        }
     }
        
     int c=n;
     if(par[n]==-1){
        cout<<"IMPOSSIBLE";
        return 0;
     }
     vector<int>ans;
    
     while(c!=1){
        ans.push_back(c);
        c=par[c];   
     }
     ans.push_back(1);

     cout<<ans.size()<<endl;
     reverse(ans.begin(),ans.end());
     for(auto it:ans){
        cout<<it<<endl;
     }
}