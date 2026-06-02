#include <bits/stdc++.h>
using namespace std;
 
//written by Manisha0369
//code for CSES 
const int MAXA=1000000;
int freqarr[MAXA+1];
int mu[MAXA+1];
int lp[MAXA+1];
vector<int >primes;
using ll=long long ;
void buildMobius (int n){
    mu[1]=1;
    primes.reserve(80000);
    for(int  i=2;i<=n;i++){
        if(lp[i]==0){
            lp[i]=i;
            primes.push_back(i);
            mu[i]=-1;
        }
        for(int idx=0;idx<(int )primes.size();++idx){
            int p=primes[idx];
            ll x=1LL*i*p;
            if(x>n||p>lp[i]) break;
            lp[(int )x]=p;
            if(i%p==0){
                mu[(int )x]=0;
                break;
            }else{
                mu[(int)x]=-mu[i];
            }
        }
    }
 
}
int main (){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     int n;cin>>n;
int mx=0;
for(int i=0;i<n;i++){
    int x;cin>>x;
    ++freqarr[x];
    if(x>mx) mx=x;
 
}
buildMobius(mx);
ll ans=0;
for(int d=1;d<=mx;++d){
    if(mu[d]==0){
        continue;
    }
    int cnt=0;
    for(int j=d;j<=mx;j+=d){
        cnt+=freqarr[j];
 
    }
    ans+=1LL*mu[d]*cnt*(cnt-1)/2;
 
}
cout<<ans<<"\n";
 
 
 
 
    return 0;
