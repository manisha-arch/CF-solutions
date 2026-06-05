#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
using i128=__int128_t;
//written by Manisha0369
//code for cses
struct P{
    ll x,y;

};
i128 cross(const P& a,const P& b,const P& c){
    return (i128)(b.x-a.x)*(c.y-a.y)-(i128)(b.y-a.y)*(c.x-a.x);
}
bool onseg(const P& a, const P& b, const P& p){
    if(cross(a,b,p)!=0) return  false;
    return min(a.x,b.x)<=p.x &&p.x<=max(a.x,b.x) && min(a.y,b.y)<=p.y &&p.y<=max(a.y,b.y);
}
string locate_p(const vector<P>& ply,const P& p){
    int wind=0;
    int n=(int )ply.size();
    P prev=ply[n-1];
    for(int i=0;i<n;++i){
        P cur=ply[i];

        if(onseg(prev,cur,p)) return "BOUNDARY";
        if(prev.y<=p.y){
            if(cur.y>p.y  && cross(prev,cur,p)>0){
                ++wind;}
                            }else{
                                if(cur.y<=p.y && cross(prev,cur,p)<0){
                                    --wind;
                                }
                            }
                            prev=cur;
        }
return (wind==0 ? "OUTSIDE" :"INSIDE");
    
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int n,m;cin>>n>>m;
   vector<P> ply(n);
    for (int i = 0; i < n; ++i) {
        cin >> ply[i].x >> ply[i].y;
    }
    while(m--){
         P p;cin>>p.x>>p.y;
         cout<<locate_p(ply,p)<<"\n";

    }


    return 0;
}