#include<iostream>
using namespace std;
int findset(int i, int parent[])
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
int main()
{
	return 0;
}