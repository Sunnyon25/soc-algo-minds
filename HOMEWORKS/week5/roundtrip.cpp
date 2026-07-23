#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, parent;
int start = -1, last = -1;

bool dfs(int v) {

    vis[v] = 1;

    for (int u : adj[v]) {

        if (vis[u] == 0) {

            parent[u] = v;

            if (dfs(u))
                return true;

        } else if (vis[u] == 1) {

            start = u;
            last = v;
            return true;
        }
    }

    vis[v] = 2;

    return false;
}

int main() {

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {

        if (vis[i] == 0) {

            if (dfs(i))
                break;
        }
    }

    if (start == -1) {

        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;

    path.push_back(start);

    int v = last;

    while (v != start) {

        path.push_back(v);
        v = parent[v];
    }

    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";

    for (int v : path) {
        cout << v << " ";
    }

    return 0;
}