#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movie;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movie.push_back({b, a});
    }

    sort(movie.begin(), movie.end());

    multiset<int> endTime;

    for (int i = 0; i < k; i++) {
        endTime.insert(0);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int start = movie[i].second;
        int end = movie[i].first;

        auto it = endTime.upper_bound(start);

        if (it == endTime.begin())
            continue;

        it--;

        endTime.erase(it);
        endTime.insert(end);

        ans++;
    }

    cout << ans;

    return 0;
}