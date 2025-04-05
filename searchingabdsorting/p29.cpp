#include <bits/stdc++.h>
using namespace std;

using ll=long long ;


bool isposs(ll mid, vector<int>nums,int k){


    int c=1;
    ll sum=0;

    int i=0;

    while(i<nums.size()){
        if(nums[i]>mid){
            return false;
        }
           if(sum+nums[i]>mid){
            sum=0;
            c++;
           }else{
            sum+=nums[i];
            i++;
           }
    }
    if(c>k){
        return false;
    }
    return true;
}
int main(){


    int n,k;
    cin>>n>>k;
     

    vector<int>nums;

    for(int i=0;i<n;i++){

        int a;
        cin>>a;
      nums.push_back(a);
    }

  ll l=0;
  ll r=1e18;
  ll ans=0;
 while(l<=r){

    ll mid= (r+l)/2;
    if(isposs(mid,nums,k)){
        ans=mid;
        r=mid-1;
    }else{
        l=mid+1;
    }
 }
      
cout<<ans;
}