#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

class trienode {
public:
    unordered_map<char, trienode*> child;
    bool isend = false;
};

class trie {
public:
    trienode* root;
    trie() {
        root = new trienode();
    }

    void insert(string& word) {
        trienode* node = root;
        for (auto ch : word) {
            if (!node->child.count(ch)) {
                node->child[ch] = new trienode();
            }
            node = node->child[ch];
        }
        node->isend = true;
    }
};

int main() {
    string a;
    cin >> a;
    int n;
    cin >> n;

    int len = a.length();
    trie t;

    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        t.insert(b);
    }

    vector<int> dp(len + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < len; i++) {
        trienode* node = t.root;
        for (int j = i; j < len; j++) {
            char h = a[j];
            if (!node->child.count(h)) break;
            node = node->child[h];
            if (node->isend)
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
        }
    }

    cout << dp[len] << endl;
}
