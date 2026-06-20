#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//written by Manisha0369
//code for CSES
#define pb push_back
#define pii pair<int, int>
//this is an editorial soln from codeforces blog 
//credits to  BaoCoder613 blog 

 const int MAXN=200005;
int a[MAXN], b[MAXN], pos[MAXN], g[MAXN], ans[MAXN], bad[MAXN];
queue <pii> qu;
 
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++){
        cin>>b[i];
        pos[b[i]]=i;
        g[a[i]]=b[i];
    }
    for(int i=1; i<=n; i++){
        ans[i]=g[g[a[i]]];
        if(ans[i]==a[i]){
            if(!bad[i]) qu.push({i, pos[a[i]]});
            bad[pos[a[i]]]=1;
            bad[i]=1;
        }
    }
    pii temp1, temp2;
    while(qu.size()>1){
        temp1=qu.front();
        qu.pop();
        temp2=qu.front();
        qu.pop();
        swap(ans[temp1.first], ans[temp2.first]);
        swap(ans[temp2.second], ans[temp1.second]);
        bad[temp1.first]=bad[temp2.first]=bad[temp1.second]=bad[temp2.second]=0;
    }
    if(!qu.empty()){
        int x1=0, x2=0;
        if(n==2){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        temp1=qu.front();
        qu.pop();
        for(int i=1; i<=n; i++){
            if(x1 && x2) break;
            if(!bad[i]){
                if(x1) x2=i;
                else x1=i;
            }
        }
        swap(ans[temp1.first], ans[x1]);
        swap(ans[temp1.second], ans[x2]);
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
}