#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>temp(n+1);
vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++){
          int a,b;
          cin>>a>>b;
          temp[a].push_back(b);
          indegree[b]++;
    }

queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
     q.push(i);
        }
    }
vector<int>ans;
    while(!q.empty()){

        int k=q.front();
        ans.push_back(k);

        q.pop();

        for(auto it:temp[k]){
              indegree[it]--;
              if(indegree[it]==0){
                q.push(it);
              }
        }
    }

   if(ans.size()==n){
    for(auto it:ans){
        cout<<it<<" ";
    }
   }else{
  cout<<"IMPOSSIBLE";
   }
}