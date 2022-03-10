#include<iostream>
#define ll long long unsigned int
using namespace std;
ll x, y, GCD;
//To calculate the remainder
void ExtendedEucledMethod(ll a, ll b)
{
	//Base Case
	if (b == 0)
	{
		x = 1;
		y = 0;
		GCD = a;
		return;
	}
	ExtendedEucledMethod(b, a % b);
	//Recursive Case
	ll cx = y;
	ll cy = x - (a / b) * y;
	x = cx;
	y = cy;
}
int main()
{
	ll n;
	cin >> n;
	ll *a = new ll[n];
	ll *rem = new ll[n];
	ll *pp = new ll[n];
	ll *inverse = new ll[n];
	ll product = 1;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		product = product * a[i];
	}
	for (ll j = 0; j < n; j++)
	{
		cin >> rem[j];
	}
	for (ll i = 0; i < n; i++)
	{
		pp[i] = product / a[i];
	}
	for (ll i = 0; i < n; i++)
	{
		ExtendedEucledMethod(pp[i], a[i]);
		inverse[i] = (x + a[i]) % a[i];
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ans = (ans + ((rem[i] * pp[i]) % product * inverse[i]) % product) % product;
	}
	cout << ans << endl;
}