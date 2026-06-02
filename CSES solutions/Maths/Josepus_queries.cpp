#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define ll long long
const ll MOD = 1e9+7;
//written by Manisha0369
//code for cses
ll solve(ll n, ll k) {
    
if(n==1) return 1;
 
if(k<=(n+1)/2){
if(n<k*2) return (2*k) %n;
return 2*k;
}
ll res=solve(n/2,k-(n+1)/2);
 
if(n%2==1) return 2*res+1 ;
return 2*res-1;
}
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t;cin>>t;
while(t--){
    ll n,m;cin>>n>>m;
   cout<< solve(n,m)<<"\n";
}
 
    return 0;
}
