#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> sz;

int find(int v) {

    if (parent[v] == v)
        return v;

    return parent[v] = find(parent[v]);
}

void unite(int a, int b) {

    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}

int main() {

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int comp = n;
    int mx = 1;

    while (m--) {

        int a, b;
        cin >> a >> b;

        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {

            unite(a, b);

            comp--;

            int root = find(a);

            if (sz[root] > mx)
                mx = sz[root];
        }

        cout << comp << " " << mx << "\n";
    }

    return 0;
}