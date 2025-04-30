#include <bits/stdc++.h>
using namespace std;


void solve(string s,vector<int>&lps){

    int l=0;
    int i=1;

    while(i<s.length()){
       
        if(s[i]==s[l]){
            l++;
            lps[i]=l;
            i++;
        }else{
            if(l!=0){
                l=lps[l-1];
            }else{
                lps[i]=0;
                i++;
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int>lps(n,0);

     solve(s,lps);

    // shortest period
    int p0 = n - lps[n-1];

    vector<int> periods;
   
    
    for (int len = p0; len < n; len += p0)
        periods.push_back(len);
    // the full length
    periods.push_back(n);

    // output in increasing order
    for (int x : periods)
        cout << x << " ";
    cout << "\n";

    return 0;
}
