


#include <bits/stdc++.h>
using namespace std;


int main(){

    string s;
    cin>>s;
     int  n=s.length();

    string ans=s;

    for(int i=0;i<n;i++){
         
        char f=s[0];
        s.erase(0,1);
        s+=f;
        if(ans>s){
            ans=s;
        }

    }
    cout<<ans;
}