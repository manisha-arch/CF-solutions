#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define ll long long
const ll MOD = 1e9+7;
const int MAXN=1e6+5;
//written by Manisha0369
//code for cses
int divisor[MAXN];
void solve() {
   for(int i=1;i<=MAXN;i++){
    for(int j=i;j<=MAXN ;j+=i){
        divisor[j]++;
    } 
   }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
       int t;cin>>t;
       while(t--){
        int n;
        cin>>n;
 
    cout<<divisor[n]<<"\n";
       }
    return 0;
}
