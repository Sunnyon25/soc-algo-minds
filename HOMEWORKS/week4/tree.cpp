#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> bfs(int start, vector<vector<int>> &adj) {

    int n = adj.size() - 1;

    vector<int> dist(n + 1, -1);

    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {

        int v = q.front();
        q.pop();

        for (int u : adj[v]) {

            if (dist[u] == -1) {

                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    int node = start;

    for (int i = 1; i <= n; i++) {

        if (dist[i] > dist[node])
            node = i;
    }

    return {node, dist[node]};
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto first = bfs(1, adj);
    auto second = bfs(first.first, adj);

    cout << second.second;

    return 0;
}