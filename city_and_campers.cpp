#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];

multiset<int>sizes;
void make(int v)
{
    parent[v]=v;
    Size[v]=1;
    sizes.insert(1);
}
int Find(int v){
    if(v==parent[v])return v;
    return parent[v]=Find(parent[v]);
}

void merge(int a,int b){

sizes.erase(sizes.find(Size[a]));
sizes.erase(sizes.find(Size[b]));

sizes.insert(Size[a]+Size[b]);

}


void Union(int a,int b){
a=Find(a);
b=Find(b);

if(a!=b){
if(Size[a]<Size[b])
    swap(a,b);
    parent[b]=a;
    merge(a,b);
    Size[a]+=Size[b];
}


}


int main(){
int n,q;
cin>>n>>q;
for(int i=1;i<=n;i++)make(i);

while(q--){
    int u,v;
    cin>>u>>v;
    Union(u,v);

    if(sizes.size()==1)cout<<0<<endl;
    else{
        int mn=*(sizes.begin());
        int mx=*(--sizes.end());
        cout<<mx-mn<<endl;
    }
}
}
