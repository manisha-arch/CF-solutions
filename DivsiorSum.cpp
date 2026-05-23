#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define ll long long
const ll MOD = 1e9+7;
//written by Manisha0369
//code for cses
void solve() {
    ll n;
    cin >> n;
 ll ans=0;
    for (ll i = 1; i <= n; ) {

        ll q = n / i;

        ll j = n / q;

        ll cnt = j - i + 1;
        ll sum;

        if ((i + j) % 2 == 0)
            sum = ((i + j) / 2) % MOD * (cnt % MOD) % MOD;
        else
            sum = (i + j) % MOD * ((cnt / 2) % MOD) % MOD;

        ans = (ans + (q % MOD) * sum) % MOD;

        i = j + 1;
    }

    cout << ans % MOD << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}