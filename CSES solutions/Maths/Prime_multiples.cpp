#include <bits/stdc++.h>
using namespace std;
//written by Manisha0369
//code for cses
#define AUTHOR 'Manisha0369'
using ll=long long;
ll n ;
int k;
vector<ll> primes;
 
 
ll solve (){
  ll res=0;
  for(int mask=1; mask<(1<<k);mask++){
    ll prod=1;
    int bits=0;
    for(int i=0;i< k;i++){
        if(mask&(1<<i)){
            bits++;
            if(prod>n/primes[i]){prod=n+1;
            break;}
            prod*=primes[i];
        }
    }
  
  if(prod>n) continue;
 
  if(bits%2==1){
    res+=n/prod;
 
 
}
else{
    res-=n/prod;
} 
  }
return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
primes.resize(k);
for(int i=0;i<k;i++){
    cin>>primes[i];
}
 
      cout<<solve()<<"\n";
return 0;
