#include <bits/stdc++.h>
using namespace std;
//written by Manisha0369
//code for cses
#define AUTHOR 'Manisha0369'
using ll=long long;
const ll MOD =1e9+7;
const ll MOD_EXP =2*(MOD-1);
ll power  (ll a ,ll b,ll c){
    ll ans =1;
    b%=c;
    while(b>0){
        if(b &1) {ans =(ans*a)% c;}
        a=(a*a)%c;
        b>>=1;
    }
    return ans;
 
}
ll mod_inverse(ll a ){
    return power(a,MOD-2,MOD);
}
void solve (){
  
  int n;cin>>n;
  vector<pair<ll,ll>> prime(n);
  ll num_div=1;
  ll sum_div=1;
  ll count_div=1;
  for(int i=0;i<n;i++){
    int p,k;cin>>p>>k;
    prime[i]={p,k};
    num_div=(num_div*((k+1)%MOD))%MOD;
    count_div=(count_div*((k+1)%MOD_EXP))%MOD_EXP;
    ll numerator=(power(p,k+1,MOD)-1+MOD)%MOD;
    ll denominator=mod_inverse((p-1+MOD)%MOD);
    ll term=(numerator*denominator)%MOD;
    sum_div=(sum_div*term)%MOD;
 
}
ll product=1;
for(int i=0;i<n;i++){
    ll p=prime[i].first;
    ll k=prime[i].second;
    ll exponent=(k%MOD_EXP*count_div)%MOD_EXP;
    exponent =(exponent/2)%(MOD-1);
    product =(product*power(p,exponent ,MOD))%MOD;
 
}
cout <<num_div<<" "<<sum_div<<" "<<product <<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
return 0;
}