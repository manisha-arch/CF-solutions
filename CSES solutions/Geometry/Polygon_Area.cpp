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
string toString(i128 x){
    if(x==0) return "0";
    bool neg=(x<0);
    if(neg) x=-x;

    string a ;
    while(x>0){
        a.push_back(char('0'+x%10));
        x/=10;

    }
    if(neg) a.push_back('-');
    reverse(a.begin(),a.end());
    return a;
}


int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<Point> p(n);
    for( int i=0;i<n;++i){
        
        cin>>p[i].x>>p[i].y;

    }
    i128 darea=0;
    for(int i=0;i+1<n;++i){
        darea+=(i128)p[i].x*p[i+1].y-(i128)p[i].y*p[i+1].x;

    }
    darea +=(i128)p[n-1].x*p[0].y-(i128)p[n-1].y*p[0].x;
    if(darea<0) darea = -darea;
    cout<<toString(darea)<<"\n";
    return 0;
}
