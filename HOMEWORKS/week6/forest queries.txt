//forest queries
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            char ch;
            cin >> ch;

            pre[i][j] = (ch == '*');

            pre[i][j] += pre[i - 1][j];
            pre[i][j] += pre[i][j - 1];
            pre[i][j] -= pre[i - 1][j - 1];
        }
    }

    while (q--) {

        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = pre[y2][x2]
                - pre[y1 - 1][x2]
                - pre[y2][x1 - 1]
                + pre[y1 - 1][x1 - 1];

        cout << ans << "\n";
    }

    return 0;
}

//