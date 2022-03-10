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
#define MAX 			100005
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
ll a[MAX], prime_count[MAX], mobius[MAX];
//nloglogn like sieve
void calculate_mobius()
{
	for (ll i = 1; i < MAX; i++)
	{
		a[i] = 1;
	}
	for (ll i = 2; i < MAX; i++)
	{
		if (prime_count[i]) continue;
		for (ll j = i; j < MAX; j += i)
		{
			prime_count[j]++;
			a[j] *= i;
		}
	}
	for (ll i = 1; i < MAX; i++)
	{
		//square free number
		if (a[i] == i)
		{
			if (prime_count[i] % 2 == 0)
			{
				mobius[i] = 1;
			}
			else
			{
				mobius[i] = -1;
			}
		}
		else
		{
			mobius[i] = 0;
		}
	}
}
ll powers2[MAX];
ll freq[MAX];
void solve()
{
	ll ans = 0;
	calculate_mobius();
	ll n;
	cin >> n;
	ll b[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];
		freq[b[i]]++;
	}
	//calculating powers of 2
	powers2[0] = 1;
	for (int i = 1; i < MAX; i++)
	{
		powers2[i] = (powers2[i - 1] * 2) % mod;
	}
	ans = 0;
	for (ll i = 1; i < MAX; i++)
	{
		ll cnt = 0;
		for (ll j = i; j < MAX; j += i)
		{
			cnt += freq[j];
			cnt %= mod;
		}
		//total many numbers are divisible by i
		ll total = (powers2[cnt] - 1);
		ans = (ans + (total * mobius[i]) % mod) % mod;
		//cout << ans << " i=" << i << " total=" << total << " cnt=" << cnt << endl;
	}
	cout << (ans + mod) % mod << endl;
}
int main()
{
	fast_io();
	solve();
	return 0;
}