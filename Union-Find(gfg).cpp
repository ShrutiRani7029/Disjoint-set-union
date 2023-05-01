class Solution
{
    public:
    //Function to merge two nodes a and b.
    
    int Find(int v,int par[]){
        
        if(v==par[v])return v;
        return par[v]=Find(par[v],par);
    }
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //code here
        a=Find(a,par);
        b=Find(b,par);
        
        if(a==b)return;
        if(rank1[a]<=rank1[b]){
            par[a]=b;
            rank1[b]+=rank1[a];
        }
        else
        {
            par[b]=a;
            rank1[a]+rank1[b];
        }
        
      }
    
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        return (Find(x,par)==Find(y,par));
    }
};
