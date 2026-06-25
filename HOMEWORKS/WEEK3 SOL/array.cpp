#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));

    if (arr[0] == 0) {
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    }
    else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {

        if (arr[i] == 0) {

            for (int v = 1; v <= m; v++) {

                dp[i][v] = dp[i - 1][v];

                if (v > 1)
                    dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % MOD;

                if (v < m)
                    dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % MOD;
            }
        }
        else {

            int v = arr[i];

            dp[i][v] = dp[i - 1][v];

            if (v > 1)
                dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % MOD;

            if (v < m)
                dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % MOD;
        }
    }

    long long ans = 0;

    if (arr[n - 1] == 0) {

        for (int v = 1; v <= m; v++) {
            ans = (ans + dp[n - 1][v]) % MOD;
        }
    }
    else {
        ans = dp[n - 1][arr[n - 1]];
    }

    cout << ans;

    return 0;
}