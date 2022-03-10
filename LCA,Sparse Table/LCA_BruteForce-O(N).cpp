
/*
    INPUT:-
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
const int N=100000;
vector<int> gr[N];
int depth[N],parent[N];
void dfs(int curr,int par,int dep)
{
    parent[curr]=par;
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
//Complexity=O(N)
int LCA(int x,int y)
{
    if(x==y) return x;
    //To make depth of x always greater than or equal to depth of y
    if(depth[x]<depth[y]) swap(x,y);
    while(depth[x]>depth[y])
    {
        x=parent[x];
    }
    //They are at the same level
    while(x!=y)
    {
        x=parent[x];
        y=parent[y];
    }
    return x;

    
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
   /* for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<depth[i]<<" "<<parent[i]<<"\n";
    }*/
    cout<<LCA(18,16)<<"\n";
    cout<<LCA(9,9)<<"\n";
    cout<<LCA(9,2)<<"\n";
}