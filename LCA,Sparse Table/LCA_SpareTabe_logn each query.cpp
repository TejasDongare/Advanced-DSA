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
int depth[N],parent[N][M];
void dfs(int curr,int par,int dep)
{
    depth[curr]=dep;
    for(auto child:gr[curr])
    {
        if(child!=par)
        {
            dfs(child,curr,dep+1);
        }
    }
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
int LCA(int u,int v)
{
    if(u==v)    return u;
    //Making depth of U always greater than all equal to depth V
    if(depth[u]<depth[v])   swap(u,v);
    int diff=depth[u]-depth[v];
    //0th column means 2^0 th parent=1 and if 1 column means 2^1 th parent`````
    for(int i=M-1;i>=0;i--)
    {
        if((diff>>i)&1)
        {
            u=parent[u][i];
        }
    }
    if(u==v)    return u;
    for(int i=M-1;i>=0;i--)
    {
        if(parent[u][i]!=parent[v][i])
        {
            u=parent[u][i];
            v=parent[v][i];
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
    dfs(1,0,0);
    build_sparse(1,0);
    cout<<LCA(15,15)<<endl;

}