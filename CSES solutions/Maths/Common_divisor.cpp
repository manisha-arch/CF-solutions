#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define ll long long
const ll MOD = 1e9+7;
const int MAXV=1e6+5;
//written by Manisha0369
//code for cses
 
int freq[MAXV]; 
int cnt[MAXV];
   
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int maxval=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        freq[x]++;
        maxval=max(maxval,x);
    }
    for(int i=1;i<=maxval;i++){
for(int j=i;j<=maxval;j+=i){
    
    cnt[i]+=freq[j];
    
}
 
}
for(int i=maxval;i>=2;i--){
    if(cnt[i]>=2){
        cout<<i<<"\n";
        return 0;
    }
 
}
 
    cout<<1<<"\n";
    return 0;
}