#include <bits/stdc++.h>
using namespace std;
//written by Manisha0369
//code for cses 
#define AUTHOR 'Manisha0369'
using ll=long long ;
using i128=__int128_t;
struct Point{
    ll x,y;

};
int orientation(const Point& a,const Point& b,const Point& c){
    i128 cross=(i128)(b.x-a.x)*(c.y-a.y)-(i128)(b.y-a.y)*(c.x-a.x);
    if(cross>0) return 1;
    if(cross<0) return -1;
    return 0;

}
bool onseg(Point a, Point b, Point p){
    return min(a.x,b.x)<=p.x &&p.x<= max(a.x,b.x) &&
    min(a.y,b.y)<=p.y && p.y<=max(a.y,b.y);
}
bool inter (Point a, Point b,Point c,Point d){
    int o1=orientation(a,b,c),o2=orientation(a,b,d);
    int o3=orientation(c,d,a),o4=orientation(c,d,b);
    if(o1!=o2 && o3!=o4) return true;
if(o1==0 && onseg(a,b,c)) return true;
if(o2==0 && onseg(a,b,d)) return true;
if(o3==0 && onseg(c,d,a)) return true;
if(o4==0 && onseg(c,d,b)) return true;
return false;
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        Point a,b,c,d;
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        cout<<(inter(a,b,c,d) ?"Yes\n" : "No\n");
    }
}
