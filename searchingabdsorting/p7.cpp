#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int>temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }

    sort(temp.begin(),temp.end());


   int m=n/2;
   long long  ele=temp[m];

long long  cost=0;
   for(int i=0;i<n;i++){
       cost+=abs(temp[i]-ele);
   }
   cout<<cost;
}