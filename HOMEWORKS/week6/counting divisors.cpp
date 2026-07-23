//counting divisors
#include <iostream>
#include <vector>
using namespace std;

int main() {

    const int MAX = 1000000;

    vector<int> divs(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++) {

        for (int j = i; j <= MAX; j += i) {
            divs[j]++;
        }
    }

    int n;
    cin >> n;

    while (n--) {

        int x;
        cin >> x;

        cout << divs[x] << "\n";
    }

    return 0;
}