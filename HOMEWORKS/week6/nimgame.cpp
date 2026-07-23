//nimgame
#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int xr = 0;

        for (int i = 0; i < n; i++) {

            int v;
            cin >> v;

            xr ^= v;
        }

        if (xr == 0)
            cout << "second\n";
        else
            cout << "first\n";
    }

    return 0;
}