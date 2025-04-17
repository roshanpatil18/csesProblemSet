#include<bits/stdc++.h>


using namespace std;

const int MAXN = 200005;
const int LOG = 19;

int up[MAXN][LOG]; // up[v][j] = 2^j-th ancestor of v
int main(){


int n,q;



cin>>n>>q;
vector<int>boss(n+1,0);

for(int i=2;i<=n;i++){
    int boss;
    cin >> boss;
    up[i][0] = boss;
}

up[1][0]=0;

for(int j=1;j<LOG;j++){

for(int i=1;i<=n;i++){


    int mid=up[i][j-1];
if(mid){
    up[i][j]=up[mid][j-1];
}else{
    up[i][j]=0;
}
}
}

while(q--){

    int x,k;
    cin>>x>>k;

    for(int i=LOG-1;i>=0;i--){
        if(k&(1<<i)){
            x=up[x][i];
            if(x==0){
                break;
            }
        }
  

    }
    cout<<(x==0?-1:x)<<" ";
}

}