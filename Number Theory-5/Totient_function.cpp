#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;
ll Totient_function(ll n)
{
	ll ans = n;
	for (ll i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n = n / i;
			}
			ans = (ans - (ans / i));
		}
	}
	if (n != 1) ans = (ans - (ans / n));
	return ans;
}
int main() {
	ll t;
	cin >> t;
	while (t--)
	{
		ll temp;
		cin >> temp;
		cout << Totient_function(temp) << endl;
	}
}