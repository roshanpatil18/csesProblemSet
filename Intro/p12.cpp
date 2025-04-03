#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    int oddCount = 0;
    char oddChar = '\0';
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            oddChar = char(i + 'A');
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    string firstHalf = "", secondHalf = "";
    
    for (int i = 0; i < 26; i++) {
        string part(freq[i] / 2, char(i + 'A'));  
        firstHalf += part;
    }

    secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    if (oddCount == 1) {
        cout << firstHalf << oddChar << secondHalf;
    } else {
        cout << firstHalf << secondHalf;
    }
}
