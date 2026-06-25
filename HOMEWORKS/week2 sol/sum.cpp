#include <iostream>
#include <map>
using namespace std;

int main() {

    int n, v;
    cin >> n >> v;

    map<int, int> pos;

    for (int i = 1; i <= n; i++) {

        int num;
        cin >> num;

        if (pos.count(v - num)) {
            cout << pos[v - num] << " " << i;
            return 0;
        }

        pos[num] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}