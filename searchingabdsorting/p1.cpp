#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    int m;
    int k;

    cin>>n;
    cin>>m;
    cin>>k;

    vector<int>app(n);
    vector<int>appartment(m);

    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        cin>>app[i];
    }
    for(int i=0;i<m;i++){
        
        cin>>appartment[i];
        pq.push(appartment[i]);
    }

    sort(app.begin(),app.end(),greater<int>());
    
   

     
    int i=0;
    int ans=0;
    
      

    while(i<app.size() && !pq.empty()){

        int maxi=app[i]+k;
        int mini=app[i]-k;

        if(pq.top()>=mini && pq.top()<=maxi){
            ans++;
            i++;
            pq.pop();
        }else if(pq.top()>maxi){
            pq.pop();
        }else{
            i++;
        }

       
    }
    cout<<ans<<endl;
}