#include<bits/stdc++.h>
using namespace std;
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
struct dsu
{
	vector<int> par;
	void init(int n)
	{
		par.resize(n);
		iota(par.begin(),par.end(),0);
	}
	//Return the super parent of x
	int find(int x)
	{
		return (x==par[x] ? x:par[x]=find(par[x]));
	}
	void unint(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x!=y)
		{
			int px=par[x];
			int py=par[y];
			par[x]=max(px,py);
			par[y]=max(px,py);
		}
	}
};
int main()
{
	fast_io();
	int n,q;
	cin>>n>>q;
	int l[q],r[q],c[q];
	dsu g;
	g.init(n+2);//as we aree uniting n with n+1
	for (int i = 0; i < q; i++)
	{
		cin>>l[i]>>r[i]>>c[i];
	}
	int res[n+2];
	for(int i=q-1;i>=0;i--)
	{
		int index=g.find(l[i]);
		while(index<=r[i])
		{
			res[index]=c[i];
			g.unint(index,index+1);
			index=g.find(index);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<res[i]<<'\n';
	}
}