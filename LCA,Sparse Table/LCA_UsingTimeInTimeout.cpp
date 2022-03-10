/*
    input
    19
    1 2 
    1 3
    2 4
    2 5
    3 10
    3 11
    5 6
    11 12
    6 7
    6 8
    6 9
    12 13
    12 14
    12 15
    15 16
    10 17
    17 18
    17 19
*/
#include <bits/stdc++.h>
using namespace std;
const int N=100005,M=22;
vector<int> gr[N];
int depth[N],parent[N][M],tin[N],tout[N],timer;
void dfs(int curr,int par,int dep)
{
    tin[curr]=++timer;
    depth[curr]=dep;
    for(auto child:gr[curr])
    {
        if(child!=par)
        {
            dfs(child,curr,dep+1);
        }
    }
    tout[curr]=timer;
    return ;
}
//this is like dfs only we can also merge the above dfs and this function
void build_sparse(int curr,int par)
{
    parent[curr][0]=par;   
    for(int j=1;j<M;j++)
    {
        parent[curr][j]=parent[parent[curr][j-1]][j-1];
    }
    for(auto x:gr[curr])
    {
        if(x!=par)
        {
            build_sparse(x,curr);
        }
    }
}
bool is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v] and tout[u]>=tout[v]);
}
int LCA(int u,int v)
{
    if(is_ancestor(u,v))    return u;
    if(is_ancestor(v,u))    return v;
    for(int i=M-1;i>=0;i--)
    {
        //if parent[u][i] is not an ancestor of v then move u 
        if(!(is_ancestor(parent[u][i],v)))
        {
            u=parent[u][i];
        }
    }
    return parent[u][0];
}
int main() 
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    tin[0]=0;tout[0]=n+1;
    timer=0;
    dfs(1,0,0);
    build_sparse(1,0);
    cout<<LCA(8,9)<<endl;
}