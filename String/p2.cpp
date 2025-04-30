

#include <bits/stdc++.h>
using namespace std;


void computelps(string s,vector<int>&lps){


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
                lps[l]=0;
                i++;
            }
        }
    }
}
int main(){

string a,b;

cin>>a>>b;

int l=a.length();
int l2=b.length();

vector<int>lps(l2,0);


computelps(b,lps);
 
int i=0;
int j=0;
int ans=0;

while(i<l){
    if(a[i]==b[j]){
        i++;
        j++;
    }
    if(j==l2){

        ans++;
        j=lps[j-1];


    }else if(i<l && a[i]!=b[j]){
        if(j!=0){

            j=lps[j-1];
        }else{
            i++;
        }
    }
}
cout<<ans;
}