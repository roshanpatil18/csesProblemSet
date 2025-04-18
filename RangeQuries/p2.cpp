

#include <bits/stdc++.h>

using namespace std;

using ll=long long;
ll maxin=2e5 + 5;
vector<ll>tree(4*maxin);
vector<long long> arr;

void build(int node,int start,int end){

    if(start==end){
        tree[node]=arr[start];
    }else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node]=min(tree[node*2],tree[2*node+1]);

    }
}


ll query(int node,int start,int end,int l,int r){

    if(r<start ||end<l){
        return LLONG_MAX;
    }

    if(l<=start && r>=end){
        return tree[node];
    }

    int mid=(start+end)/2;

    ll left=query(2*node,start,mid,l,r);
    ll right=query(2*node+1,mid+1,end,l,r);

    return min(left,right);



}
int main(){


    int n,q;
    cin>>n>>q;

    arr.resize(n + 1); // 1-based indexing
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }



    build(1,1,n);

    while(q--){

        int a,b;
        cin>>a>>b;
        cout<<query(1,1,n,a,b)<<endl;
    }
}
 