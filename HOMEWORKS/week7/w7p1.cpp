#include <iostream>
#include <vector>
using namespace std;

int main() {

    string s, p;
    cin >> s >> p;

    int n = s.size();
    int m = p.size();

    vector<int> lps(m);

    for (int i = 1, j = 0; i < m; ) {

        if (p[i] == p[j]) {

            lps[i] = ++j;
            i++;
        }
        else {

            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }

    int ans = 0;

    for (int i = 0, j = 0; i < n; ) {

        if (s[i] == p[j]) {

            i++;
            j++;

            if (j == m) {

                ans++;
                j = lps[j - 1];
            }
        }
        else {

            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }

    cout << ans;

    return 0;
}