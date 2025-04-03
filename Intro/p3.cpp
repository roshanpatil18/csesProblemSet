#include <bits/stdc++.h>
using namespace std;



int main(){

    string s;
    cin>>s;

       int ans=1;
       int maxi=1;


       for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
           maxi++;
          
        }else{
            maxi=1;
        }
        ans=max(ans,maxi);
       }
cout<<ans;
 
}

