#include <bits/stdc++.h>
using namespace std;


int main(){




    int n;
    cin>>n;

    vector<pair<int,int>>temp;
     int i=0;
     int a,b;
  while(n--){
    cin>>a>>b;
temp.push_back({a,1});
temp.push_back({b,-1});
       i++;
  }

  sort(temp.begin(),temp.end());

  int maxi=0;
  int c=0;

  for(auto it:temp){
       
    c+=it.second;
    maxi=max(maxi,c);
       
  }
  cout<<maxi;


}