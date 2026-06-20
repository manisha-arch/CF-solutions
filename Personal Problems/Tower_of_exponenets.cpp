#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define ll long long
const ll MOD = 1e9+7;

//written by Manisha0369
//code for cses

ll power(ll base, ll exp, ll mod) {
    ll ans =1;
    base%=mod;
    while(exp>0){
        if(exp & 1) {
            ans=(ans*base)%mod;

        }
        base=(base*base)%mod;
        exp>>=1;
    }
   return ans;
    } 
   
ll towerpow(vector<ll>& tower, int idx ,ll mod){
   
    if(mod ==1) return 0;
    if(idx==tower.size()-1){
        return tower[idx]%mod;
    }
    ll exp=towerpow(tower,idx+1,mod-1);
    return power(tower[idx],exp,mod);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
       int t;cin>>t;
       while(t--){
        int n;cin>>n;
        vector<ll> tower1(n);
        for(int i=0;i<n;i++){
            cin>>tower1[i];
        }
        cout    <<towerpow(tower1,0,MOD)<<"\n";

       }
    return 0;
}