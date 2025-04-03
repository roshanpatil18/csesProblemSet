#include <bits/stdc++.h>
using namespace std;

 void solve(string s,set<string>&ab,int i,string t, vector<int>vis){

      if(i==s.length()){
        ab.insert(t);
        return ;
      }

      for(int j=0;j<s.length();j++){
           
        if(!vis[j]){
            vis[j]=1;
            solve(s,ab,i+1,t+s[j],vis);
            vis[j]=0;
        }
      }
 }

int main(){


    string s;
    cin>>s;

    set<string>ab;
    vector<int>vis(s.length(),0);
    solve(s,ab,0,"",vis);
       cout<<ab.size()<<endl;
    for(auto it:ab){
        cout<<it<<endl;
    }

}