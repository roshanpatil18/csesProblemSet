#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> num;
    vector<vector<int>> temp(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        num.push_back({a, b});
        temp[a].push_back(b);
        temp[b].push_back(a);
    }

      
    vector<int>vis(n+1,0);


    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(bfs(temp,i,vis)){
                
            }
        }
    }
}