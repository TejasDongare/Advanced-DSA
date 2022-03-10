#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqmx             priority_queue<ll>//max heap
#define pqmn             priority_queue<ll,vi,greater<ll> >//min heap
#define setbits(x)      __builtin_popcountll(x)//Number of set bits in a number
#define zerobits(x)      __builtin_ctzll(x)//number of zeros after the first 1 from right example 1010=1 only 1 one after the first one from right
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x//precision
#define mk(arr,n,type)  type *arr=new type[n];//dynamic array
#define w(x)            ll x; cin>>x; while(x--)//Test case
#define nl				cout<<endl;//new line 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());//shuffler

#define primemax 100005
vector<int> primes;
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void sieve()
{
	int a[primemax] = {0};
	for (ll i = 2; i <= primemax; i++)
	{
		if (!a[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= primemax; j += i)
			{
				a[j] = 1;
			}
		}
	}
}
ll fast_exponentiation(ll n, ll p)
{
	ll power = n;
	ll answer = 1;
	while (p > 0)
	{
		ll last_bit = p & 1;
		if (last_bit)
		{
			answer *= (power * last_bit);
		}
		power = power * power;
		p = p >> 1;
	}
	return answer;
}
ll fact_for_ncr(ll n, ll r)
{
	ll res = 1;
	for (ll i = n; i >= n - r + 1; i--)
		res = (res * i) / (n - i + 1);
	return res;
}
ll nCr(ll n, ll r)
{
	return fact_for_ncr(n, r);
}
//Time Complexity:-O(sqrt(n))
vector<ll> prime_factor(ll num)
{
	vector<ll> pf;
	for (ll i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			while (num % i == 0)
			{
				num = num / i;
				pf.push_back(i);
			}
		}
	}
	if (num != 1) pf.push_back(num);
	return pf;
}
//First Calculate Prime Sieve then each query will take O(logn) Time
vector<ll> factorize_using_sieve(ll m)
{
	vector<ll> factors;
	ll p = primes[0];
	ll i = 0;
	while (p * p <= m)
	{
		if (m % p == 0)
		{
			while (m % p == 0)
			{
				factors.pb(p);
				m = m / p;
			}
		}
		i++;
		p = primes[i];
	}
	if (m != 1) factors.pb(m);
	return factors;
}
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a , b); //Formula LCM=(A*B)/GCD(A,B)
}
ll x, y, GCD;
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
	fast_io();
	//18x+30y=6
	ExtendedEucledMethod(6, 7);
	cout << x << " , " << y << endl;
	return 0;
}