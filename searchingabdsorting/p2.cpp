#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int w;
    cin >> w;

    vector<int> stud(n);
    for (int i = 0; i < n; i++){
        cin >> stud[i];
    }


    sort(stud.begin(), stud.end());

    int i = 0;        
    int j = n - 1;     
    int ans = 0;       

    while(i <= j){
       
        if(i == j){
            ans++;
            break;
        }

    
        if(stud[i] + stud[j] <= w){
           
            i++;
            j--;
            ans++;
        } else {
          
            j--;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
