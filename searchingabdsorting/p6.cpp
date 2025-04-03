#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int>temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }


    long long maxi=INT_MIN;
    long long ans=0;
    for(int i=0;i<n;i++){
           ans+=temp[i];
           maxi=max(maxi,ans);
           if(ans<0){
            ans=0;
           }
          
    }
    cout<< maxi;

    
}