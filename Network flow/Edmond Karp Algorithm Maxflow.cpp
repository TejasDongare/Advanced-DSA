/*
	input data:-
				5 7
				0 2 100
				0 3 50
				2 3 50
				2 4 50
				3 4 100
				2 1 50
				4 1 125
*/
#include<bits/stdc++.h>
using namespace std;
bool bfs(int **residualcapacity,int source,int sink,int n,int *parent)
{
	bool visited[n];
	memset(visited,0,sizeof(visited));
	queue<int> que;
	visited[source]=true;
	que.push(source);
	bool foundAugmentPath=false;
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		for(int v=0;v<n;v++)
		{
			if(visited[v]==false and residualcapacity[u][v]>0)
			{
				parent[v]=u;
				visited[v]=true;
				que.push(v);
				if(v==sink)
				{
					foundAugmentPath=true;
					break;
				}
			}
		}
	}
	return foundAugmentPath;
}
void printAugmentedPath(vector<vector<int>> augmentedpaths)
{
	for(int i=0;i<augmentedpaths.size();i++)
	{
		for(int j=0;j<augmentedpaths[i].size();j++)
		{
			cout<<augmentedpaths[i][j]<<" ";
		}
		cout<<endl;
	}
}
int maxflow(int **capacity,int source,int sink,int v)
{
	int** residualcapacity=new int*[v];
	for(int i=0;i<v;i++)
	{
		residualcapacity[i]=new int[v];
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			residualcapacity[i][j]=capacity[i][j];
		}
	}
	int *parent=new int[1000];
	vector<vector<int>> augmentedpaths;
	int maxflow=0;
	while(bfs(residualcapacity,source,sink,v,parent))
	{
		vector<int> currentAugmentedPath;
		int flow=INT_MAX;
		int v=sink;
		while(v!=source)
		{
			currentAugmentedPath.push_back(v);
			int u=parent[v];
			if(flow>residualcapacity[u][v])
			{
				flow=residualcapacity[u][v];
			}
			v=u;
		}
		//as we know we have did reversed traced that is from sink to source but we want source to sink so reverse
		currentAugmentedPath.push_back(source);
		std::reverse(currentAugmentedPath.begin(),currentAugmentedPath.end());
		augmentedpaths.push_back(currentAugmentedPath);
		maxflow+=flow;
		v=sink;
		while(v!=source)
		{
			int u=parent[v];
			residualcapacity[u][v]-=flow;
			residualcapacity[v][u]+=flow;
			v=u;
		}
	}
	printAugmentedPath(augmentedpaths);
	return maxflow;
}
int main()
{
	int v,e;
	cin>>v>>e;
	int **capacity=new int*[v];
	for(int i=0;i<v;i++)
	{
	    capacity[i]=new int[v];
	}
	for(int i=0;i<e;i++)
	{
	    int u,v,c;
	    cin>>u>>v>>c;
	    capacity[u][v]=c;
	}
	cout<<maxflow(capacity,0,1,v);
}