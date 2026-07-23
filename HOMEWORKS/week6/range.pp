//range
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main() {

    int n;
    cin >> n;

    vector<vector<array<ll,3>>> dp(n + 1,
        vector<array<ll,3>>(n + 2));

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {

            // k = 0
            if (j + 1 <= n) {
                dp[i][j][0] =
                    (dp[i][j][0]
                    + 1LL * j * (j + 1) % MOD * dp[i - 1][j + 1][0]) % MOD;

                dp[i][j][0] =
                    (dp[i][j][0]
                    + 1LL * j * j % MOD * dp[i - 1][j + 1][1]) % MOD;

                dp[i][j][0] =
                    (dp[i][j][0]
                    + 1LL * j * (j - 1) % MOD * dp[i - 1][j + 1][2]) % MOD;
            }

            // k = 1
            dp[i][j][1] =
                (dp[i][j][1]
                + 2LL * j % MOD * dp[i - 1][j][0]) % MOD;

            dp[i][j][1] =
                (dp[i][j][1]
                + (2LL * j - 1) * dp[i - 1][j][1]) % MOD;

            dp[i][j][1] =
                (dp[i][j][1]
                + (2LL * j - 2) * dp[i - 1][j][2]) % MOD;

            dp[i][j][1] %= MOD;

            // k = 2
            dp[i][j][2] =
                (dp[i - 1][j - 1][0]
                + dp[i - 1][j - 1][1]
                + dp[i - 1][j - 1][2]) % MOD;
        }
    }

    ll ans = 0;

    for (int k = 0; k < 3; k++) {
        ans = (ans + dp[n][1][k]) % MOD;
    }

    cout << ans;

    return 0;
}