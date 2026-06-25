#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int pos[n + 1];

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        pos[v] = i;
    }

    int ans = 1;

    for (int i = 2; i <= n; i++) {

        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}