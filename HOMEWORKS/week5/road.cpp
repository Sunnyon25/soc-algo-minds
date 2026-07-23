#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Edge {
    int a, b;
    ll c;
};

vector<int> parent, sz;

int find(int v) {

    if (parent[v] == v)
        return v;

    return parent[v] = find(parent[v]);
}

bool unite(int a, int b) {

    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];

    return true;
}

bool cmp(Edge x, Edge y) {
    return x.c < y.c;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<Edge> edge(m);

    for (int i = 0; i < m; i++) {
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    }

    sort(edge.begin(), edge.end(), cmp);

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    ll ans = 0;
    int cnt = 0;

    for (auto e : edge) {

        if (unite(e.a, e.b)) {

            ans += e.c;
            cnt++;
        }
    }

    if (cnt != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << ans;

    return 0;
}