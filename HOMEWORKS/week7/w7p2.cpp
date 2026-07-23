#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

struct Node {

    int next[26];
    bool end;

    Node() {

        for (int i = 0; i < 26; i++)
            next[i] = -1;

        end = false;
    }
};

int main() {

    string s;
    cin >> s;

    int n = s.size();

    int k;
    cin >> k;

    vector<Node> trie(1);

    for (int i = 0; i < k; i++) {

        string v;
        cin >> v;

        int cur = 0;

        for (char c : v) {

            int x = c - 'a';

            if (trie[cur].next[x] == -1) {

                trie[cur].next[x] = trie.size();
                trie.push_back(Node());
            }

            cur = trie[cur].next[x];
        }

        trie[cur].end = true;
    }

    vector<int> dp(n + 1);

    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {

        int cur = 0;

        for (int j = i; j < n; j++) {

            int x = s[j] - 'a';

            if (trie[cur].next[x] == -1)
                break;

            cur = trie[cur].next[x];

            if (trie[cur].end) {

                dp[i] += dp[j + 1];

                if (dp[i] >= MOD)
                    dp[i] -= MOD;
            }
        }
    }

    cout << dp[0];

    return 0;
}