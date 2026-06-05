#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//written by Manisha0369
//code for CSES
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;

    vector<int> ans(n);
    int l = 0, r = n - 1;

    for (int x = 1; x <= n; x++) {
        ll mx = r - l;

        if (k >= mx) {
            ans[r] = x;
            k -= mx;
            r--;
        } else {
            int pos = l + (int)k;
            ans[pos] = x;

            int curr = x + 1;

            for (int i = l; i < pos; i++) {
                ans[i] = curr++;
            }

           
            for (int i = pos + 1; i <= r; i++) {
                ans[i] = curr++;
            }

            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}