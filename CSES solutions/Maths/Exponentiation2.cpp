#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define AUTHOR 'Manisha0369'
const ll MOD = 1e9 + 7;
//written by Manisha0369
//code for cses
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
    
        
       
        ll expo = power(b, c, MOD - 1);
        
        
        ll ans= power(a, expo, MOD);
        
        cout << ans << "\n";
    }
    
    return 0;
}