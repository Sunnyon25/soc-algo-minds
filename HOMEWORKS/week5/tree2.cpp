#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n;
vector<vector<int>> adj;
vector<int> sz;
vector<ll> ans;

void dfs1(int v, int p, int depth) {

    sz[v] = 1;
    ans[1] += depth;

    for (int u : adj[v]) {

        if (u == p)
            continue;

        dfs1(u, v, depth + 1);

        sz[v] += sz[u];
    }
}

void dfs2(int v, int p) {

    for (int u : adj[v]) {

        if (u == p)
            continue;

        ans[u] = ans[v] - sz[u] + (n - sz[u]);

        dfs2(u, v);
    }
}

int main() {

    cin >> n;

    adj.resize(n + 1);
    sz.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}