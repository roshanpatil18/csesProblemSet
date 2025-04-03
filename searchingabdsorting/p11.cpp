#include <bits/stdc++.h>
using namespace std;

int main() {

   
    int n;
    cin>>n;
vector<int>temp;
    for(int i=0;i<n;i++){
           int a;
           cin>>a;
        auto it=upper_bound(temp.begin(),temp.end(),a);

        if(it==temp.end()){
            temp.push_back(a);
        }else{
            *it=a;
        }
    }
        
cout<<temp.size();
   

}