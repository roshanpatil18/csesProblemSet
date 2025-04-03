#include <bits/stdc++.h>
using namespace std;

int main(){
 int t;
 cin>>t;
 while(t--){

 
    int x,y;
    cin>>x>>y;

 int a,b;

 if(x>=y){
    a=x;
    b=y;
 }else{
    a=y;
    b=x;
 }


 if(2*b<a ){
    cout<<"NO"<<endl;
   continue;
 }


     

int c=x%3;
int d=y%3;

if((c==0 && d==0) ||(c==2 && d==1)|| (c==1 && d==2) ){
    cout<<"YES"<<endl;
  continue;
}
cout<<"NO"<<endl;
}
}