#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

vector<int>num(n);

for(int i=0;i<n;i++){
    cin>>num[i];
}
long long ans=0;
for(int i=1;i<n;i++){
 if(num[i]<num[i-1]){
    ans+=num[i-1]-num[i];
    num[i]=num[i-1];
 }


}
cout<<ans;
}