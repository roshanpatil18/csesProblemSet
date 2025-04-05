#include <bits/stdc++.h>
using namespace std;


int main(){

 int n,k;
 cin>>n>>k;

 vector<int>nums;

 for(int i=0;i<n;i++){
    int a;

    cin>>a;
    nums.push_back(a);
 }


 long long ans=0;

 unordered_map<int,int>mp;
int j=0;
 for(int i=0;i<n;i++){



       mp[nums[i]]++;

       if(mp.size()>k){
        while(mp.size()!=k){
            mp[nums[j]]--;
          
            if(mp[nums[j]]==0){
                mp.erase(nums[j]);
            }
            j++;
        }
       }

       long long l=i-j;
       ans+=i-j+1;
 }
cout<<ans;
}