#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N];
void make(int v)
{
    parent[v]=v;
}
int Find(int v){
    if(v==parent[v])return v;
    return parent[v]=Find(parent[v]);
}



void Union(int a,int b){

    parent[a]=b;
}



int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
            make(i);
        }
    while(q--){

        int type;
        cin>>type;
        if(type==1){
            int a,b;
            cin>>a>>b;
            a=Find(a);
            b=Find(b);

            if(a!=b){
                Union(a,b);
            }
        }else if(type==2){
            int a;
            cin>>a;
            int k=Find(a);
            parent[k]=a;
            parent[a]=a;

        }
        else
        {
            int a;
            cin>>a;
            cout<<Find(a)<<endl;
        }


    }
}
