#include <bits/stdc++.h>
using namespace std;



bool isposs(int mid,vector<  long long>temp ,int m){

    long long c=0;

    for(int i=0;i<temp.size();i++){
        c+=mid/temp[i];
    }
    if(c>=m){
        return true;
    }
    return false;

}
int main(){


    int n,m;
    cin>>n>>m;
vector<  long long>temp;
    for(int i=0;i<n;i++){
        long long a;
  cin>>a;
  temp.push_back(a);
    }


    long long  l=0;
    long long r=INT_MAX;
    long long ans=-1;
    while(l<=r){

        int mid=l+(r-l)/2;

        if(isposs(mid,temp,m)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}