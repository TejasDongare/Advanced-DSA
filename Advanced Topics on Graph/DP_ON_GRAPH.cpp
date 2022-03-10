/*
    INPUT:-
            12 16
            1 3 
            1 9
            9 12
            12 11
            11 9
            3 5
            5 7
            7 3
            5 1
            3 6
            6 1
            2 6
            2 4
            4 10
            3 8
            8 2
*/
#include <bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> gr[N];
int dp[N],visited[N],depth[N];
void dfs(int curr,int par,int dep)
{
    dp[curr]=dep;
    visited[curr]=1;
    depth[curr]=dep;
    for(auto x:gr[curr])
    {
        if(visited[x]==0)
        {
            dfs(x,curr,dep+1);
            dp[curr]=min(dp[curr],dp[x]);
        }
        //backedge
        else if(x!=par)
        {
            dp[curr]=min(dp[curr],depth[x]);
        }
    }
    
    return ;
}
int main() 
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    //Tree is rooted on 1
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<dp[i]<<endl;
    }
}