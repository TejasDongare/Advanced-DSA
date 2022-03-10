/*
    input   
    8 9
    1 2 
    2 3 
    1 3 
    3 4 
    4 8
    4 5
    5 6
    6 7
    7 4
*/
#include <bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> gr[N];
int discovery[N],lowest[N];
set<int> articulation_point;
vector<pair<int,int>> bridges;
void dfs(int curr,int par,int &timer)
{
    discovery[curr]=lowest[curr]=timer++;
    int no_child=0;
    for(auto child:gr[curr])
    {
        //not visited
        if(discovery[child]==0)
        {
            dfs(child,curr,timer);
            no_child++;
            lowest[curr]=min(lowest[curr],lowest[child]);
            //Articulation Point par!=0 means we are talking about root 1 whose parent =0 we have to handle it sepreately
            if(par!=0 and lowest[child]>=discovery[curr])
            {
                articulation_point.insert(curr);
            }
            //Bridge
            if(lowest[child]>discovery[curr])
            {
                bridges.push_back({curr,child}); 
            }
        }
        else if(child!=par)
        {
            //Backedges
            lowest[curr]=min(lowest[curr],discovery[child]);
        }
    }
    //Seprate case for root to be articulation point
    if(par==0 and no_child>=2)
    {
        articulation_point.insert(curr);
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
        int timer=1;
        dfs(1,0,timer);
        cout<<"articulation Point"<<endl;
        for(auto x:articulation_point)
        {
            cout<<x<<" ";
        }
        cout<<endl<<"Bridges=";
        for(auto x:bridges)
        {
            cout<<"("<<x.first<<","<<x.second<<") , ";
        }
        cout<<endl;
}