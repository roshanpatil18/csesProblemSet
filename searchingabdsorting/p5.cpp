#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int,int>> movies;
    int a, b;
   
    for (int i = 0; i < n; i++){
       cin >> a >> b;
    
       movies.push_back({b, a});
    }

   
    sort(movies.begin(), movies.end());

    int ans = 1;
    int lastFinish = movies[0].first;

 
    for (int i = 1; i < n; i++){
    
        if (movies[i].second >= lastFinish){
            ans++;
            lastFinish = movies[i].first;  
        }
    }
    
    cout << ans;
    return 0;
}
