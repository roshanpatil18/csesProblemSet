

#include <bits/stdc++.h>
using namespace std;


void solve(string s,vector<int>&lps){

    int l=0;
    int i=1;

    while(i<s.length()){
       
        if(s[i]==s[l]){
            l++;
            lps[i]=l;
            i++;
        }else{
            if(l!=0){
                l=lps[l-1];
            }else{
                lps[i]=0;
                i++;
            }
        }

    }
}
int main(){

    string s;
    cin>>s;
    int n=s.length();

    vector<int>lis(n,0);

    // 0 0 0 0 1 2 1 2 3 4
    solve(s,lis);

    int len=lis[n-1];
    vector<int>ans;
    for(auto it:lis){
        cout<<it<<" ";
    }cout<<endl;
    while(len!=0){
      ans.push_back(len);
      len=lis[len-1];
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
}