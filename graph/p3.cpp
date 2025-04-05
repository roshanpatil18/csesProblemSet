#include <bits/stdc++.h>
using namespace std;



class Disjoint {
    public:
        vector<int> rank, parent;
    
        Disjoint(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
    
        int findUP(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findUP(parent[node]);
        }
    
        void unionr(int u, int v) {
            int pu = findUP(u);
            int pv = findUP(v);
            if (pu == pv) return;
    
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };

int main(){



    int n,m;
   cin>>n>>m;
    Disjoint d(n+1);

 vector<pair<int,int>>temp;
    for(int i=0;i<m;i++){
               int a,b;
               cin>>a>>b;
               temp.push_back({a,b});
              
              
    }



    for(auto it:temp){
        int a=it.first;
        int b=it.second;
       d.unionr(a,b);

    }

      int j=1;
      int ans=0;
      vector<pair<int,int>>a;
   for(int i=2;i<=n;i++){
       if(d.findUP(i)!=d.findUP(j)){
        ans++;
        a.push_back({j,i});
        d.unionr(i,j);

       }
   }
    if(ans){
        cout<<ans<<endl;
        for(auto it:a){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }else{

        cout<<0;
    }
    
}