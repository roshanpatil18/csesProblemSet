#include <bits/stdc++.h>
using namespace std;


int main(){

   int n;
   cin>>n;
long long total=0;


   for(int i=1;i<=n;i++){
        total+=i;
   }

   if(total&1){
      cout<<"NO"<<endl;
   }else{
       total=total/2;
         cout<<"YES"<<endl;
       long long sum=0;
       int i=1;
       int a=0;
       while(sum<=total){
sum+=i;
i++;
       }
       i--;
       if(sum>total){
        a=sum-total;
       }
       if(a!=0){
         cout<<i-1<<endl;
       }else{
         cout<<i<<endl;
       }
       for(int j=1;j<=i;j++){
         if(j==a) continue;
         cout<<j<<" ";
       }
       cout<<endl;
       if(a!=0){
         cout<<n-i+1<<endl;
       }else{
         cout<<n-i<<endl;
       }
       if(a!=0){
         cout<<a<<" ";
       }
       for(int j=i+1;j<=n;j++){
                cout<<j<<" ";
       }
   }
    
}