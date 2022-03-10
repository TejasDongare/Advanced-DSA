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
	freopen("output1.txt", "w", stdout);
#endif
}
ll fast_exponentiation(ll a, ll b, ll m)
{

	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}
ll solve(ll n, ll p)
{
	ll ans = -1;
	for (ll i = n + 1; i <= p - 1; i++)
	{
		ans = (ans * fast_exponentiation(i, p - 2, p)) % p;
	}
	return (ans + p) ;
}
int main()
{
	fast_io();
	ll t, n, p;
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		if (n >= p)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << solve(n, p) << endl;
		}
	}
	return 0;
}