#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>>temp;

    for(int i=0;i<n;i++){

        int a,b;
        cin>>a>>b;
        temp.push_back({a,{b,i}});
    }

   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;


        sort(temp.begin(),temp.end());
        vector<int>ans(n,-1);
         int r=1;
         int i=temp[0].second.second;
        pq.push({temp[0].second.first,temp[0].second.second});
       ans[i]=r;
       r++;
    
        for(int i=1;i<n;i++){
            auto it=pq.top();

            if(it.first<temp[i].first){
                pq.pop();
                int j=temp[i].second.second;
                int k=it.second;
                ans[j]=ans[k];
                pq.push({temp[i].second.first,j});
            }else{
                int j=temp[i].second.second;
                pq.push({temp[i].second.first,j});
                ans[j]=r;
                r++;
            }
        }

        cout<<r-1<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }

}