#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> lis;

    for (int i = 0; i < n; i++) {

        int v;
        cin >> v;

        auto it = lower_bound(lis.begin(), lis.end(), v);

        if (it == lis.end()) {
            lis.push_back(v);
        }
        else {
            *it = v;
        }
    }

    cout << lis.size();

    return 0;
}