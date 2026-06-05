#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//written by Manisha0369
//code for CSES
void solve (){
     int n,k;cin>>n>>k;
    if(1LL *k*k<n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int >p;
    for(int s=1;s<=n;s+=k){
        int end=min(n,s+k-1);
        for(int x=end;x>=s;--x){
            p.push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        if(i) cout<<' ';
        cout<<p[i];
    }
    cout<<'\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t;cin>>t ;
 while (t--){
    solve();
 }
 return 0;


       

}