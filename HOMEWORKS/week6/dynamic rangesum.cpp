dynamic rangesum
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll BASE = 911382323;

struct BIT {

    int n;
    vector<ll> bit;

    BIT(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void add(int idx, ll val) {

        val %= MOD;
        if (val < 0) val += MOD;

        while (idx <= n) {
            bit[idx] += val;
            bit[idx] %= MOD;
            idx += idx & -idx;
        }
    }

    ll sum(int idx) {

        ll ans = 0;

        while (idx > 0) {
            ans += bit[idx];
            ans %= MOD;
            idx -= idx & -idx;
        }

        return ans;
    }

    ll query(int l, int r) {

        ll ans = sum(r) - sum(l - 1);

        ans %= MOD;
        if (ans < 0) ans += MOD;

        return ans;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    s = " " + s;

    vector<ll> pw(n + 2), inv(n + 2);

    auto power = [&](ll a, ll b) {

        ll ans = 1;

        while (b) {

            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    };

    pw[0] = 1;

    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * BASE % MOD;

    inv[n] = power(pw[n], MOD - 2);

    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * BASE % MOD;

    BIT f(n), r(n);

    for (int i = 1; i <= n; i++) {

        ll val = s[i] - 'a' + 1;

        f.add(i, val * pw[i] % MOD);

        int pos = n - i + 1;
        r.add(pos, val * pw[pos] % MOD);
    }

    while (m--) {

        int t;
        cin >> t;

        if (t == 1) {

            int k;
            char c;
            cin >> k >> c;

            ll old = s[k] - 'a' + 1;
            ll now = c - 'a' + 1;

            f.add(k, (now - old) * pw[k]);

            int pos = n - k + 1;
            r.add(pos, (now - old) * pw[pos]);

            s[k] = c;
        }
        else {

            int l, rr;
            cin >> l >> rr;

            ll h1 = f.query(l, rr);
            h1 = h1 * inv[l] % MOD;

            int rl = n - rr + 1;
            int rr2 = n - l + 1;

            ll h2 = r.query(rl, rr2);
            h2 = h2 * inv[rl] % MOD;

            if (h1 == h2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}