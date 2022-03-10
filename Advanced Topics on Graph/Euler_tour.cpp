#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int> gr[N];
vector<int> et1;
int tin1[N],tout1[N];
int tin2[N],tout2[N];
int tin3[N],tout3[N];
void euler_tour_1(int curr,int par,int &timer)
{
	cout<<curr<<" ";
	tin1[curr]=timer;
	et1.push_back(curr);
	for(auto x:gr[curr])
	{
		if(x!=par)
		{
		    timer++;
			euler_tour_1(x,curr,timer);
			cout<<curr<<" ";
			et1.push_back(curr);
			timer++;
		}
	}
	tout1[curr]=timer;
	return ;
}
void euler_tour_2(int curr,int par,int &timer)
{
	cout<<curr<<" ";
	tin2[curr]=timer++;
	for(auto x:gr[curr])
	{
		if(x!=par)
		{
			euler_tour_2(x,curr,timer);
		}
	}
	cout<<curr<<" ";
	tout2[curr]=timer++;
}
void euler_tour_3(int curr,int par,int &timer)
{
	tin3[curr]=++timer;
	cout<<curr<<" ";
	for(auto x:gr[curr])
	{
		if(x!=par)
		{
			euler_tour_3(x,curr,timer);
		}
	}
	tout3[curr]=timer;
	return ;
}
//Whether x is ancestor of y or not
bool is_ancestor(int x,int y)
{
    return (tin3[x]<=tin3[y] and tout3[x] >= tout3[y]) ? 1:0; 
}
void solve()
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
	int timer=1;
	cout<<"Euler Tour 1"<<endl;
	euler_tour_1(1,0,timer);
	timer=1;
	cout<<endl<<"Euler Tour 2"<<endl;
	euler_tour_2(1,0,timer);
	cout<<endl<<"Euler Tour 3"<<endl;
	timer=0;
	euler_tour_3(1,0,timer);
	cout<<endl<<"Time in and time out for 3rd euler tour"<<endl;
	for(int i=1;i<=n;i++)
	{
	    cout<<i<<" "<<tin1[i]<<" "<<tout1[i]<<endl;
	}
	if(is_ancestor(3,8))
	{
	    cout<<"Yes"<<endl;
	}
	else
	{
	    cout<<"NO"<<endl;
	}
}
int main()
{
	solve();
}