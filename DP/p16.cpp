#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, pair<int, int>>>& num, int i, vector<int>& end_times) {
    if (i == num.size()) return 0;

    int inc = 0, exc = 0;
    int end = num[i].second.first;

    auto it = upper_bound(end_times.begin(), end_times.end(), end);
    int index = it - end_times.begin();

    inc = num[i].second.second + solve(num, index, end_times);
    exc = solve(num, i + 1, end_times);

    return max(inc, exc);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> num;
    vector<int> end_times;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        num.push_back({a, {b, c}});
    }

   
    sort(num.begin(), num.end());

   
    for (auto& p : num) end_times.push_back(p.first);


     vector<int>dp(n+1,0);

     for(int i=n-1;i>=0;i--){

        int inc=0;
        int exc=0;
        int end = num[i].second.first;
        auto it = upper_bound(end_times.begin(), end_times.end(), end);
         int index=it-end_times.begin();
         inc=num[i].second.second+dp[index];
         exc=dp[i+1];

         dp[i]=max(inc,exc);


     }
cout<<dp[0];         
}
