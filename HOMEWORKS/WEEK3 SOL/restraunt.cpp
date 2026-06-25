#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> event;

    for (int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;

        event.push_back({a, 1});
        event.push_back({b, -1});
    }

    sort(event.begin(), event.end());

    int curr = 0;
    int ans = 0;

    for (int i = 0; i < event.size(); i++) {

        curr += event[i].second;

        if (curr > ans)
            ans = curr;
    }

    cout << ans;

    return 0;
}