#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);

    queue<int> q;

    q.push(1);
    vis[1] = true;

    while (!q.empty()) {

        int v = q.front();
        q.pop();

        for (int u : adj[v]) {

            if (!vis[u]) {

                vis[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }
    }

    if (!vis[n]) {

        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;

    int v = n;

    while (v != -1) {

        path.push_back(v);
        v = parent[v];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";

    for (int v : path) {
        cout << v << " ";
    }

    return 0;
}