#include <bits/stdc++.h>
using  namespace std;
using ll =long long ;
#define AUTHOR 'Manisha0369'
const ll MOD = 1e9 + 7;
typedef unsigned long long ull  ;
typedef __int128 lll;
 
ll mulmod(ll a, ll b , ll c ){
    return (__int128 ) a*b%c;
}
ll powmod(ll base, ll exp, ll m) {
    ll result = 1;
    base %= m;
    
    while(exp > 0) {
        if(exp & 1) {                         
            result = mulmod(result, base, m);
        }
        base = mulmod(base, base, m);
        exp >>= 1;                           
    }
    return result;
}
bool millertest(ll n,ll m){
    if(n%m==0) return n==m;
    ll d =n-1;
     int r=0;
     while(d%2==0){
        d/=2;
    r++;
     }
     ll x=powmod(m,d,n);
     if(x==1|| x==n-1) return true;
     for( int i=0;i<r-1;i++){
        x=mulmod(x,x,n);
        if(x==n-1)return true;
 
     }
     return false;
}
 
bool isPrime(ll n) {
    if(n < 2)  return false;
    if(n == 2) return true;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    if(n < 9)  return true;
    if(n % 3 == 0) return false;
    
 
    for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(!millertest(n, a)) return false;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
     int t;cin>>t;
     while(t--){
        ll n ;cin>>n;
        ll cand=n+1;
        if(cand<=2){
            cout<<2<<"\n";
            continue;
        }
        if(cand%2==0) cand++;
 
    while(!isPrime(cand)){
            cand+=2;
 
        }
        cout<<cand<<"\n";
     }
 
    
     return 0;
}
