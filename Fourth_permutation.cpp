#include <bits/stdc++.h>
using namespace std;
//it is a personal problem which i thought i can do 
/*
if there are three permutation given and u have to create permutation 
such that it is not equal to any ofthe permuation array given 
*/
#define pb push_back
#define pii pair<int, int>

const int MAXN=200005;
int a[MAXN], b[MAXN], c[MAXN], pos[MAXN], g[MAXN], ans[MAXN], bad[MAXN];
queue <pii> qu;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     int n; cin>>n;

     for(int i=0;i<n;i++) cin>>a[i];
      for(int i=0;i<n;i++) cin>>b[i];
       for(int i=0;i<n;i++) cin>>c[i];
       
       for(int i=0;i<n;i++){
        pos[c[i]] = i;
        g[a[i]] = b[i];
       }
         map<int, int> gb, gc;  
    
    for(int i = 0; i < n; i++){
      
        g[a[i]] = b[i];
       
        gb[b[i]] = c[i];
        gc[c[i]] = a[i];
    }
        for(int i=0;i<n;i++){
             int temp1 = g[c[i]];     
            int temp = c[i];
        temp = g[temp];       
        temp = gb[temp];        
        ans[i] = gc[temp];


            if(ans[i]==a[i] || ans[i]==b[i] || ans[i]==c[i]){
                if(!bad[i] ) qu.push({i,pos[a[i]]});
                bad[pos[a[i]]]=1;
                bad[i]=1;
            }
        }
        pii t1,t2;
        while(qu.size()>1){
            t1=qu.front(); qu.pop();
            t2=qu.front();qu.pop();
            swap(ans[t1.first],ans[t2.first]);
            swap(ans[t1.second],ans[t2.second]);
            bad[t1.first]=bad[t2.first]=bad[t1.second]=bad[t2.second]=0;

        }
        if(!qu.empty()){
            if(n==2){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
            t1=qu.front();
            qu.pop();
            int x1=0,x2=0;
            for(int i=0;i<n;i++){
                if(x1 && x2) break;
                if(!bad[i]){
                    if(x1) x2=i;
                    else x1=i;
        }
    
    }
    
    swap(ans[t1.first],ans[x1]);
    swap(ans[t1.second],ans[x2]);
}
for(int i=0;i<n;i++) cout<<ans[i]<<" ";
cout<<"\n";
return 0;
}