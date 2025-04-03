#include <bits/stdc++.h>
using namespace std;

int ans=0;

void solve(int n,vector<pair<int,int>>&ab,int a,int b,int c){


    if(n==1){
       ab.push_back({a,c});
       ans++;
       return ;

    }

   solve(n-1,ab,a,c,b);

   ab.push_back({a,c});
   ans++;

   solve(n-1,ab,b,a,c);




}
int main(){


    int n;
    cin>>n;
  vector<pair<int,int>>ab;
  int a=1;
  int b=2;
  int c=3;
    solve(n,ab,a,b,c);
    cout<<ans<<endl;;
    for(auto it:ab){
     
        cout<<it.first<<" "<<it.second<<endl;

    }


}