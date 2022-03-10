#include <iostream>
#include<cstring>
#include<set>
#include<climits>
using namespace std;
int ccp[100005], BITS[100005];
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void update(int i, int val, int n)
{
	while (i <= n)
	{
		BITS[i] = max(val, BITS[i]);
		i += (i & (-i));
	}
}
int query(int i)
{
	int ans = INT_MIN;
	while (i > 0)
	{
		ans = max(BITS[i], ans);
		i -= (i & (-i));
	}
	return ans;
}
int main()
{
	fast_io();
	set<pair<int, int>> s;
	int t;
	cin >> t;
	while (t--)
	{
		memset(BITS, 0, sizeof(BITS));
		int n;
		cin >> n;
		int a[n];
		int wt[n + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s.insert({a[i], i});
		}
		int i = 1;
		for (auto x : s)
		{
			ccp[x.second + 1] = i;
			i++;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> wt[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int ans = query(a[i] - 1);
			update(a[i], ans + wt[i], n);
		}
		cout << query(n) << endl;
		s.clear();
	}

}