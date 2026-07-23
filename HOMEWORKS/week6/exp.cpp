//exp
#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll power(ll a, ll b) {

    ll ans = 1;
    a %= MOD;

    while (b) {

        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    while (n--) {

        ll a, b;
        cin >> a >> b;

        cout << power(a, b) << "\n";
    }

    return 0;
}