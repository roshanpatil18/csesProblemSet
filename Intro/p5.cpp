#include <bits/stdc++.h>
using namespace std;


 void solve(int n){


    while(n>0){
        cout<<n<<" ";
        n=n-2;
    }
 }
int main(){



    int n;
    cin>>n;
    if(n==1){
        cout<<1;
    }
  else  if(n==4){
        cout<<"2 4 1 3 ";
    }
  else  if(n<4){
        cout<<"NO SOLUTION";

    }else{
        solve(n-1);
        solve(n);
    }

}