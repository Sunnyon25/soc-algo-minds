#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {

    int n;
    cin >> n;

    string p;
    cin >> p;

    int m = p.size();

    vector<int> lps(m);

    for (int i = 1, j = 0; i < m;) {

        if (p[i] == p[j]) {
            lps[i++] = ++j;
        }
        else {

            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }

    vector<vector<int>> nxt(m + 1, vector<int>(26));

    for (int i = 0; i <= m; i++) {

        for (int c = 0; c < 26; c++) {

            if (i == m) {

                int j = lps[m - 1];

                while (j && p[j] != char('A' + c))
                    j = lps[j - 1];

                if (p[j] == char('A' + c))
                    j++;

                nxt[i][c] = j;
            }
            else {

                int j = i;

                while (j && p[j] != char('A' + c))
                    j = lps[j - 1];

                if (p[j] == char('A' + c))
                    j++;

                nxt[i][c] = j;
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= m; j++) {

            if (dp[i][j] == 0)
                continue;

            for (int c = 0; c < 26; c++) {

                if (j == m) {

                    dp[i + 1][m] += dp[i][m];

                    if (dp[i + 1][m] >= MOD)
                        dp[i + 1][m] -= MOD;
                }
                else {

                    int v = nxt[j][c];

                    if (v == m) {

                        dp[i + 1][m] += dp[i][j];

                        if (dp[i + 1][m] >= MOD)
                            dp[i + 1][m] -= MOD;
                    }
                    else {

                        dp[i + 1][v] += dp[i][j];

                        if (dp[i + 1][v] >= MOD)
                            dp[i + 1][v] -= MOD;
                    }
                }
            }
        }
    }

    cout << dp[n][m];

    return 0;
}