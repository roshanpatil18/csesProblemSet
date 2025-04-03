#include <bits/stdc++.h>
using namespace std;

int main() {

     
    int x,n;

    cin>>x>>n;

    vector<int>temp(n);

      
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }

    set<int>s;
    s.insert(0);
    s.insert(x);
    multiset<int>st;
    vector<int>ans;

    for(int i=0;i<n;i++){

         int a=temp[i];

        auto u=s.upper_bound(a);
        auto l=u;
        l--;
         
        int dis=*u-*l;
        if(st.find(dis)!=st.end()){
            st.erase(st.find(dis));
        }

        st.insert(a-*l);
        st.insert(*u-a);

        s.insert(a);

        ans.push_back(*st.rbegin());

    }

      for(auto it:ans){
        cout<<it<<" ";
      }

}