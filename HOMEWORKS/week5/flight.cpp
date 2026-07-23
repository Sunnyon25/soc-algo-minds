#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {

        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {

        int v = q.front();
        q.pop();

        topo.push_back(v);

        for (int u : adj[v]) {

            indegree[u]--;

            if (indegree[u] == 0)
                q.push(u);
        }
    }

    vector<int> dp(n + 1, -1);
    vector<int> parent(n + 1, -1);

    dp[1] = 1;

    for (int v : topo) {

        if (dp[v] == -1)
            continue;

        for (int u : adj[v]) {

            if (dp[v] + 1 > dp[u]) {

                dp[u] = dp[v] + 1;
                parent[u] = v;
            }
        }
    }

    if (dp[n] == -1) {

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