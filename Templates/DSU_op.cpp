#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//practise templates
//in this approach we attach second to first this approach als ocalled quick union 

// void naive_un(int  a,int b){
//     int rootA=find(a);
//     int rootB = find(b);
//     parent[rootB]=rootA;
// }
//weighted union 
class DSU{
    vector<int > pnt;
    vector<int > s;

public:
DSU(int n){
    pnt.resize(n);
    s.resize(n,0);
    for(int i=0;i<n;i++){
        pnt[i]=i;
    }

}
//this is path compression 
int find(int x){
    if(pnt[x]!=x){
        pnt[x]=find(pnt[x]);//compress path

    }
    return pnt[x];
}
void unite(int a,int b){
    int rA=find(a);
    int rB = find(b);

    if(rA==rB ) return ;
    if(s[rA]<s[rB]){
        pnt[rA]=rB;

    }else if(s[rA]>s[rB]){
        pnt[rB]=rA;

    }else{
        pnt[rB]=rA;
        s[rA]++;
    }
}
bool connected(int a,int b){
    return find(a)==find(b);
}
};


// void solve (){
  
// }
/*
time complexity of find O(log n)
time complexity of union O(log n)
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int n=5;
    DSU dsu(n);
    dsu.unite(0,1);
dsu.unite(1,2);
dsu.unite(3,4);
cout<<dsu.connected(0,2)<<"\n";
     cout<<dsu.connected(0,3)<<"\n";
     cout<<dsu.connected(3,4)<<"\n";
     set<int > roots;
     for(int i=0;i<n;i++){
        roots.insert(dsu.find(i));
     }  
     cout<<roots.size()<<"\n";

}