#include <bits/stdc++.h>
using namespace std;


int solve(int a,int b){

    if(a==b){
        return 0;
    }

    if(a>b){
        a=a-b;
    }else{
        b=b-a;
    }
    return 1+solve(a,b);

}
int main(){



    int a,b;
    cin>>a>>b;

    int ans=solve(a,b);
    cout<<ans;
}