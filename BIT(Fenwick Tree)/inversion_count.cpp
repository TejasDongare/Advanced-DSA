#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;
ll BIT[50000000] = {0};
void update(ll i, ll val, ll n)
{
	for (ll j = i; j <= 50000000; )
	{
		BIT[j] += val;
		j = j + (j & (-j));
	}
	return;
}
ll query(ll i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += BIT[i];
		i -= (i & (-i));
	}
	return ans;
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n + 1];
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		ll answer = 0;
		for (ll i = n; i >= 1; i--)
		{
			answer = answer + query(a[i] - 1);
			//cout<<"query[a[i]-1]"<<query(a[i]-1)<<" a[i]="<<a[i]<<endl;
			update(a[i], 1, n);
		}
		cout << answer << endl;
	}
}