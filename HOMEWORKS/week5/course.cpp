#include <iostream>
#include <vector>
#include <queue>
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

    vector<int> ans;

    while (!q.empty()) {

        int v = q.front();
        q.pop();

        ans.push_back(v);

        for (int u : adj[v]) {

            indegree[u]--;

            if (indegree[u] == 0)
                q.push(u);
        }
    }

    if (ans.size() != n) {

        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int v : ans) {
        cout << v << " ";
    }

    return 0;
}