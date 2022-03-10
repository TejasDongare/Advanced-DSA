#include<iostream>
#include<list>
using namespace std;
class graph
{
	int v;
	list<pair<int, int>> l; //(1,2) (2,3) this representation is edge list
public:
	graph(int v)
	{
		this->v = v;
	}
	int addEdge(int u, int v)
	{
		l.push_back({u, v});
	}
	//find
	void findset(int i, int parent[])
	{
		if (parent[i] == -1)
		{
			return i;
		}
		return findset(parent[i], parent);
	}
	void union_set(int x, int y, int parent[])
	{
		int s1 = findset(x, parent);
		int s2 = findset(y, parent);
		if (s1 != s2)
		{
			parent[s1] = s2;
		}
		return ;
	}
	bool contains_cycle()
	{
		//DSU logic to check if the graph contains a cycle or not
		int *parent = new int[v];
		for (int i = 0; i < v; i++)
		{
			parent[i] = -1;
		}
		for (auto edge : l)
		{
			int s1 = findset(edge.first, parent);
			int s2 = findset(edge.second, parent);
			if (s1 == s2)
			{
				return true;
			}
			union_set(s1, s2, parent);
		}
		delete [] parent;
		return false;
	}
};
int main()
{
	graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	if (g.contains_cycle())
	{
		cout << "Contains Cycle" << endl;
	}
	else
	{
		cout << "No cycle" << endl;
	}
}