#include<iostream>
#define ll long long int
#include<unordered_map>
using namespace std;
ll BIT[100005];
void update(ll i, ll value)
{
	while (i < 100005)
	{
		BIT[i] += value;
		i += (i & (-i));
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
	unordered_map<string, ll> m;
	unordered_map<string, ll> cnt;
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		string s;
		ll price;
		cin >> s >> price;
		m[s] = price;
	}
	ll q;
	cin >> q;
	ll total_elements_present = 0;
	while (q--)
	{
		string type, s;
		cin >> type;
		if (type == "+")
		{
			cin >> s;
			update(m[s], 1);
			cnt[s]++;
			total_elements_present++;
		}
		else if (type == "-")
		{
			cin >> s;
			if (cnt[s] > 0)
			{
				update(m[s], -1);
				total_elements_present--;
				cnt[s]--;
			}
		}
		else
		{
			int x;
			cin >> x;
			//Here instead of total_elements_present we can also use query(100005) this will return all the elements less than
			//100005 that is all the elements - query(x)(this will give all the elements less than x)
			cout << total_elements_present - query(x) << endl;
		}
	}
}