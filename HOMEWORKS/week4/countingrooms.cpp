#include <iostream>
#include <stack>
using namespace std;

int n, m;
char grid[1000][1000];
bool vis[1000][1000];

int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '.' && !vis[i][j]) {

                ans++;

                stack<pair<int, int>> st;
                st.push({i, j});
                vis[i][j] = true;

                while (!st.empty()) {

                    auto cur = st.top();
                    st.pop();

                    int row = cur.first;
                    int col = cur.second;

                    for (int k = 0; k < 4; k++) {

                        int nx = row + x[k];
                        int ny = col + y[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                            grid[nx][ny] == '.' && !vis[nx][ny]) {

                            vis[nx][ny] = true;
                            st.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}