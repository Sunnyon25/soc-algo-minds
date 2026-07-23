#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    const ll INF = 1e18;

    vector<ll> dist(n + 1, INF);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {

        ll d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d != dist[v])
            continue;

        for (auto u : adj[v]) {

            int to = u.first;
            int w = u.second;

            if (dist[to] > dist[v] + w) {

                dist[to] = dist[v] + w;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}