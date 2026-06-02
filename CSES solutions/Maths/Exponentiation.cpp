#include <bits/stdc++.h>
using  namespace std;
using ll =long long ;
#define AUTHOR 'Manisha0369'
const ll MOD = 1e9 + 7;
ll solve(ll n,ll m,ll mod ){
   
 
      ll ans=1;
       n%=MOD;
       if(n<0) n+=mod;
      while(m>0){
        if(m &1) {ans=(ans*n) %MOD;}
 
      
      n=(n*n)%MOD;
      m>>=1;
      }
      return ans ;
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
     int t;cin>>t;
     while(t--){
        ll n,m;cin>>n>>m;
        cout<<solve(n,m,MOD)<<"\n";
     }
     return 0;
}
