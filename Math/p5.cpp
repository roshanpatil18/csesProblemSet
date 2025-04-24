#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> freq(MAXV+1, 0);

    // read input and build freq
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    // For each g, count how many input values are multiples of g
    vector<int> countDiv(MAXV+1, 0);
    for(int g = 1; g <= MAXV; g++){
        for(int m = g; m <= MAXV; m += g){
            countDiv[g] += freq[m];
        }
    }

    // find the largest g with at least two multiples
    for(int g = MAXV; g >= 1; g--){
        if(countDiv[g] >= 2){
            cout << g << "\n";
            break;
        }
    }

    return 0;
}
